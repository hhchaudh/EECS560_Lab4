//! Haaris Chaudhry
//! ClosedHashTable.h
//! This file describes the functions and members to be used in the ClosedHashTable class

#ifndef CLOSED_HASH_TABLE_H
#define CLOSED_HASH_TABLE_H

//! According to example output from the lab description, keys will be positive values,
//! therefore we'll display -1 if a bucket is "empty"
struct Bucket
{
    Bucket() :
        wasDeleted( false ),
        key( -1 )
    {
    }

    bool wasDeleted;
    int key;
};

class ClosedHashTable
{
public:
    /**
    * Constructor
    * @param aValue The size of the list
    * @return An empty ClosedHashTable
    */
    ClosedHashTable( unsigned int aValue );

    /**
    * Destructor
    */
    ~ClosedHashTable();

    /**
    * Insertion function
    * @param aValue The value to insert in the list
    * @return A boolean indicating successful insertion where true or false indicate success or failure, respectively
    */
    bool insert( int aValue );

    /**
    * Removal function
    * @param aValue The value to remove from the list
    * @return A boolean indicating successful removal where true or false indicate success or failure, respectively
    */
    bool remove( int aValue );

    /**
    * Print function
    * @return A boolean indicating successful printing where true or false indicate that the hash is not empty or empty, respectively
    */
    bool print();

    /**
    * Function that sets whether to use quadratic hashing or not
    * @param aFlag The boolean indicating whether we want quadratic hashing (true) or not (false)
    */
    void setQuadraticHashing( bool aFlag );
private:
    Bucket* mBuckets;                   //! The array of buckets to hold keys
    const unsigned int mSIZE;           //! The size of the array
    bool mUseQuadratic;                 //! The boolean used to determine whether or not we use quadratic hashing


    /**
    * Function that checks if a given key exists
    * @param aValue The value to find in the list
    * @return A boolean indicating successful search where true or false indicate found or not found, respectively
    */
    bool contains( int aValue );

    /**
    * The hash function to be used
    * @param aValue The value that we need to get a hash value for
    * @return The hash value
    */
    int hash( int aValue );
};
#endif // !CLOSED_HASH_TABLE_H
