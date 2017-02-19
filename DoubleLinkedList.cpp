//! Haaris Chaudhry
//! DoubleLinkedList.cpp
//! This file is the implementation file for the DoubleLinkedList

#include "DoubleLinkedList.h"
#include <iostream>

//! The DoubleLinkedList Constructor
//! Initialize mFront to nullptr
DoubleLinkedList::DoubleLinkedList():mFront(nullptr)
{
}

//! The DoubleLinkedList Destructor
DoubleLinkedList::~DoubleLinkedList()
{
    Node* deleter = mFront;     //!< Used to delete a node
    Node* mover = mFront;       //!< Used to move to the next node

    while(deleter != nullptr)
    {
        mover = mover->getNext();
        delete deleter;
        deleter = mover;
    }

    mFront = nullptr;
}

//! The initial insert function
//! Returns true when a number can be inserted and false when a number already
//! exists and therefore cannot be inserted
bool DoubleLinkedList::insert(int aValue)
{
    return recursiveInsert(mFront, aValue);
}

//! The recursive portion of the insertion function
bool DoubleLinkedList::recursiveInsert(Node* aNodePtr, int aValue)
{
    if(aNodePtr && aNodePtr->getValue() == aValue)
    {
        return false;   //!< Don't insert an existing value and return false
    }

    if(!aNodePtr)   //!< Check for mFront being nullptr (The list is empty)
    {
        Node* newNode = new Node(aValue);
        mFront = newNode;
        return true;
    }
    else if(aNodePtr->getNext() == nullptr) //!< End of list, so we add node
    {
        Node* newNode = new Node(aValue);
        newNode->setPrevious(aNodePtr);
        aNodePtr->setNext(newNode);
        return true;
    }
    else
    {
        return recursiveInsert(aNodePtr->getNext(), aValue);
    }
}

//! Prints a list, if the list is empty, return false, true otherwise
bool DoubleLinkedList::print()
{
    return recursivePrint(mFront);
}

//! The recursive portion of the print function
bool DoubleLinkedList::recursivePrint(Node* aNodePtr)
{
    if(!aNodePtr)   //! mFront is nullptr, return false
    {
        return false;
    }

    std::cout << aNodePtr->getValue() << " ";

    if(aNodePtr->getNext())
    {
        return recursivePrint(aNodePtr->getNext());
    }

    return true;
}

//! The remove function takes an integer and removes that value if it exists
//! in the list.  If it does not exist, then the function returns false.  The
//! function returns true otherwise.
bool DoubleLinkedList::remove(int aValue)
{
   return recursiveRemove(mFront, aValue);
}

//! The recursive portion of the removal function.
bool DoubleLinkedList::recursiveRemove(Node* aNodePtr, int aValue)
{
    if(!aNodePtr)   //!< aValue does not exist if we get here
    {
        return false;
    }

    if(aNodePtr->getValue() == aValue)
    {
        Node* currentNode = aNodePtr;
        Node* nextNode = currentNode->getNext();
        Node* previousNode = currentNode->getPrevious();

        if(previousNode)
        {
            previousNode->setNext(nextNode);
        }
        else
        {
            mFront = nextNode;
        }

        if(nextNode)
        {
            nextNode->setPrevious(previousNode);
        }

        delete currentNode;
        return true;
    }

    return recursiveRemove(aNodePtr->getNext(), aValue);
}

//! List reversal
void DoubleLinkedList::reverse()
{
    if(!mFront || !(mFront->getNext())) //!< Preliminary Checks on mFront
    {
        return;
    }
    else
    {
        Node* referenceNode = mFront;   //!< Pointer will persist through recursion
        recursiveReverse(referenceNode, mFront);
    }
}

//! Recursive list reversal
//! Using the persistent pointer, we can start traversing through the list
//! once we recurse to the end of the list.
//! First, we save the current node value in the list in a local variable,
//! then we recurse until we get to the end of the list, once we get to the end
//! of the list, we can then initiate list traversal using the persistent pointer.
//! Each return of the recursed functions will be used to save the local value
//! to the node pointed at by the persistent pointer, and then the peristent pointer
//! will point to the next node in preparation of the next function return.
void DoubleLinkedList::recursiveReverse(Node*& aRefNode, Node* aCurrentNode)
{
    int localValue = aCurrentNode->getValue();
    if(aCurrentNode->getNext())
    {
        recursiveReverse(aRefNode, aCurrentNode->getNext());
    }
    aRefNode->setValue(localValue);
    aRefNode = aRefNode->getNext();
}

bool DoubleLinkedList::find(int aValue)
{
    return recursiveFind(mFront, aValue);
}

bool DoubleLinkedList::recursiveFind(Node* aNodePtr, int aValue)
{
    if(!aNodePtr)
    {
        return false;
    }
    else if(aNodePtr->getValue() == aValue)
    {
        return true;
    }
    else
    {
        return recursiveFind(aNodePtr->getNext(), aValue);
    }
}
