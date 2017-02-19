//! Haaris Chaudhry
//! ClosedHashTable.cpp
//! This file describes the functions and members to be used in the ClosedHashTable class

#include "ClosedHashTable.h"
#include <iostream>

ClosedHashTable::ClosedHashTable( unsigned int aSize ) :
    mSIZE( aSize ),
    mBuckets( new Bucket[aSize] ),
    mUseQuadratic( true )
{
}

ClosedHashTable::~ClosedHashTable()
{
    if( mBuckets )
    {
        delete[] mBuckets;
    }
}

bool ClosedHashTable::insert( int aValue )
{
    if( aValue > -1 )
    {
        int hx = hash( aValue );
        int hxPlus = 5 - ( aValue % 5 );                        // Function to be used in double hashing
        int insertionIndex;

        for( unsigned int i = 0; i < 60000; i++ )
        {
            if( mUseQuadratic )                                 // Check to see if we use quadratic hashing or double hashing
            {
                insertionIndex = ( hx + i*i ) % mSIZE;          // Quadratic hashing
            }
            else
            {
                insertionIndex = ( hx + i*hxPlus ) % mSIZE;     // Double hashing
            }

            if( mBuckets[insertionIndex].key == -1 )
            {
                mBuckets[insertionIndex].key = aValue;
                return true;
            }
            else if( mBuckets[insertionIndex].key == aValue)
            {
                return false;
            }
        }
    }

    return false;
}

bool ClosedHashTable::remove( int aValue )
{
    int hx = hash( aValue );
    int hxPlus = 5 - ( aValue % 5 );                            // Function to be used in double hashing
    int insertionIndex;

    for( unsigned int i = 0; i < mSIZE; i++ )
    {
        if( mUseQuadratic )                                     // Check to see if we use quadratic hashing or double hashing
        {
            insertionIndex = ( hx + i*i ) % mSIZE;              // Quadratic hashing
        }
        else
        {
            insertionIndex = ( hx + i*hxPlus ) % mSIZE;         // Double hashing
        }

        if( mBuckets[insertionIndex].key == aValue )
        {
            mBuckets[insertionIndex].key = -1;
            mBuckets[insertionIndex].wasDeleted = true;
            return true;
        }
        else if( !( mBuckets[insertionIndex].key == aValue ) && !( mBuckets[insertionIndex].key == -1 ) )
        {
            continue;                                           // Continue searching if a different value is found
        }
        else
        {
            if( ( mBuckets[insertionIndex].key == -1 ) && ( mBuckets[insertionIndex].wasDeleted ) )
            {
                continue;                                       // Continue searching if a value was deleted from the empty bucket
            }
            else if( ( mBuckets[insertionIndex].key == -1 ) && !( mBuckets[insertionIndex].wasDeleted ) )
            {
                return false;                                   // The bucket was always empty, the value is not in the table
            }
        }
    }

    return false;
}

bool ClosedHashTable::print()
{
    bool hashHasItems = false;

    for( unsigned int i = 0; i < mSIZE; i++ )
    {
        if( !( mBuckets[i].key == -1 ) )
        {
            std::cout << i << ": " << mBuckets[i].key << " flag = " << ( mBuckets[i].wasDeleted ? "true" : "false" ) << std::endl;
            hashHasItems = true;
        }
        else
        {
            std::cout << i << ": " << mBuckets[i].key << " flag = " << ( mBuckets[i].wasDeleted ? "true" : "false" ) << std::endl;
        }
    }

    return hashHasItems;
}

void ClosedHashTable::setQuadraticHashing( bool aFlag )
{
    mUseQuadratic = aFlag;
}

bool ClosedHashTable::contains( int aValue )
{
    int hx = hash( aValue );
    int hxPlus = 5 - ( aValue % 5 );                            // Function to be used in double hashing
    int insertionIndex;

    for( unsigned int i = 0; i < mSIZE; i++ )
    {
        if( mUseQuadratic )                                     // Check to see if we use quadratic hashing or double hashing
        {
            insertionIndex = ( hx + i*i ) % mSIZE;              // Quadratic hashing
        }
        else
        {
            insertionIndex = ( hx + i*hxPlus ) % mSIZE;         // Double hashing
        }

        if( !( mBuckets[insertionIndex].key == -1 ) )
        {
            if( mBuckets[insertionIndex].key == aValue )
            {
                return true;
            }
        }
        else
        {
            if( mBuckets[insertionIndex].wasDeleted )
            {
                continue;                                       // Continue searching if a value was deleted from the bucket
            }
            else
            {
                return false;
            }
        }
    }

    return false;
}

int ClosedHashTable::hash( int aValue )
{
    return ( aValue % mSIZE );
}
