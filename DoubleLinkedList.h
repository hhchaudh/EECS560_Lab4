//! Haaris Chaudhry
//! DoubleLinkedList.h
//! This file describes the functions and members to be used in the DoubleLinkedList class

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "Node.h"

class DoubleLinkedList
{
public:
    /**
    * Constructor
    * @return An empty DoubleLinkedList
    */
    DoubleLinkedList();

    /**
    * Destructor
    * @return An empty DoubleLinkedList
    */
    ~DoubleLinkedList();

    /**
    * Function used to insert values into the DoubleLinkedList
    * @param aValue Value to be inserted into the list
    * @return bool value indicating whether insertion was successful or not
    */
    bool insert(int aValue);

    /**
    * Function used to print the DoubleLinkedList
    * @return bool value that indicates whether or not there is something to print
    */
    bool print();

    /**
    * Function used to remove a value from the list.
    * @param aValue Value to be removed from the list
    * @return bool value indicating whether removal was successful or not
    */
    bool remove(int aValue);

    /**
    * Function used to reverse the values in the DoubleLinkedList
    */
    void reverse();

    /**
    * Function used to find a value in the list
    */
    bool find(int aValue);
private:
    /**
    * Pointer that points to the front of the list
    */
    Node* mFront;

    /**
    * Function used to insert a value recursively
    * @param aValue Value to be inserted
    * @param aNodePtr A pointer that points to the current node during recursion
    * @return bool value indicating whether insertion was successful or not
    */
    bool recursiveInsert(Node* aNodePtr, int aValue);

    /**
    * Function used to print values in the DoubleLinkedList
    * @param aNodePtr A pointer that points to the current node during recursion
    * @return bool value indicating whether printing was successful or not
    */
    bool recursivePrint(Node* aNodePtr);

    /**
    * Function used to remove a value recursively
    * @param aValue Value to be removed
    * @param aNodePtr A pointer that points to the current node during recursion
    * @return bool value indicating whether removal was successful or not
    */
    bool recursiveRemove(Node* aNodePtr, int aValue);

    /**
    * Function used to insert a value recursively
    * @param aNodePtr A persistent pointer that is moved during the tail end of recursion
    * @param aCurrentNode A pointer that points to the current node during recursion
    */
    void recursiveReverse(Node*& aRefNode, Node* aCurrentNode);

    /**
    * Function used to find a value recursively
    * @param aNodePtr A pointer that points to the current node during recursion
    * @param aValue The value that we're searching for
    */
    bool recursiveFind(Node* aNodePtr, int aValue);
};
#endif // !DOUBLE_LINKED_LIST_H
