//! Haaris Chaudhry
//! OpenHashTable.h
//! This file describes the functions and members to be used in the OpenHashTable class

#ifndef OPEN_HASH_TABLE_H
#define OPEN_HASH_TABLE_H

#include "DoubleLinkedList.h"

class OpenHashTable
{
public:
    /**
    * Constructor
    * @param aSize The size of the list
    * @return An empty OpenHashTable with
    */
    OpenHashTable( unsigned int aSize);

    /**
    * Destructor
    * @return An empty OpenHashTable
    */
    ~OpenHashTable();

    /**
    * Insertion Function
    * @param The value to be inserted into the hash table
    * @return A boolean indicating if insertion was successful
    */
    bool insert( int aValue );

    /**
    * Function that deletes a given value
    * @param The value to be inserted into the hash table
    * @return A boolean indicating if insertion was successful
    */
    bool deletenode( int aValue );

    /**
    * Function that finds a given value
    * @param The value to be searched for
    * @return A boolean indicating whether or not we found the value
    */
    bool find( int aValue );

    /**
    * Prints the hash table
    */
    bool print();

private:
    unsigned int hash( int aValue );
    const unsigned int mSIZE;
    DoubleLinkedList* mList;

};
#endif // !OPEN_HASH_TABLE_H
