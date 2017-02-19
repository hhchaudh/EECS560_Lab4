//! Haaris Chaudhry
//! Node.h
//! This describes the functions and members to be used in the Node class

#include "Node.h"

//! Constructor, set mValue to passed in aValue. Set both mNext and mPrevious to nullptr
Node::Node(int aValue):mValue(aValue),mNext(nullptr),mPrevious(nullptr)
{
}

// The following are just setters and getters and should be self explanatory
int Node::getValue() const
{
    return mValue;
}

void Node::setValue(int aValue)
{
    mValue = aValue;
}

Node* Node::getNext() const
{
    return mNext;
}

void Node::setNext(Node* aNodePtr)
{
    mNext = aNodePtr;
}

Node* Node::getPrevious() const
{
    return mPrevious;
}

void Node::setPrevious(Node* aNodePtr)
{
    mPrevious = aNodePtr;
}
