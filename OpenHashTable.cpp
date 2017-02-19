//! Haaris Chaudhry
//! OpenHashTable.cpp
//! This is the implementation of the OpenHashTable class
#include "OpenHashTable.h"
#include <iostream>

// The Table will be an array that contains elements that are each
// DoubleLinkedLists, the array will have aSize elements
OpenHashTable::OpenHashTable( unsigned int aSize ) : mSIZE( aSize ), mList( new DoubleLinkedList[aSize] )
{
}

OpenHashTable::~OpenHashTable()
{
    if( mList )
    {
        delete[] mList;
    }
}

bool OpenHashTable::insert( int aValue )
{
    int insertionIndex = hash( aValue );

    if( mList )
    {
        if( !find( aValue ) )  // Useless function call, used only to demonstrate that find works.
        {
            return mList[insertionIndex].insert( aValue );
        }
    }

    return false;
}

bool OpenHashTable::deletenode( int aValue )
{
    int insertionIndex = hash( aValue );

    if( mList )
    {
        if( find( aValue ) )  // Useless function call, used only to demonstrate that find works.
        {
            return mList[insertionIndex].remove( aValue );
        }
    }

    return false;
}

bool OpenHashTable::find( int aValue )
{
    unsigned int insertionIndex = hash( aValue );

    if( mList )
    {
        return mList[insertionIndex].find( aValue );
    }
    return false;
}

bool OpenHashTable::print()
{
    bool valuesPrinted = false;

    if( mList )
    {
        for( int i = 0; i < mSIZE; i++ )
        {
            std::cout << i << ": ";
            if( !mList[i].print() )
            {
                std::cout << "Empty";
            }
            else
            {
                valuesPrinted = true;
            }
            std::cout << std::endl;
        }
    }

    return valuesPrinted;
}

unsigned int OpenHashTable::hash( int aValue )
{
    return (aValue % mSIZE);
}
