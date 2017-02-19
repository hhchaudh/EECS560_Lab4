//! Haaris Chaudhry
//! Node.h
//! This describes the functions and members to be used in the Node class

#ifndef NODE_H
#define NODE_H


class Node
{
public:
    /**
    * Constructor
    * @param aValue The value to be contained by the Node
    * @return A Node with aValue as its value
    */
    Node(int aValue);

    /**
    * Returns the value of the Node
    * @return An integer representing the value of the Node
    */
    int getValue() const;

    /**
    * Sets the value of the Node
    * @param aVal An integer value to be contained by the Node
    */
    void setValue(int aVal);

    /**
    * Returns the Node that the mNext variable is pointing to
    * @return A Node pointer
    */
    Node* getNext() const;

    /**
    * Sets the value mNext
    * @param aNodePtr A pointer pointing to a Node that mNext will point to
    */
    void setNext(Node* aNodePtr);

    /**
    * Returns the Node that the mPrevious variable is pointing to
    * @return A Node pointer
    */
    Node* getPrevious() const;

    /**
    * Sets the value mPrevious
    * @param aNodePtr A pointer pointing to a Node that mPrevious will point to
    */
    void setPrevious(Node* aNodePtr);

private:
    /**
    * The value of the Node
    */
    int mValue;

    /**
    * A pointer pointing to the next Node
    */
    Node* mNext;

    /**
    * A pointer pointing to the previous Node
    */
    Node* mPrevious;
};
#endif
