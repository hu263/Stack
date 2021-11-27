#ifndef stackaslinkedlist_h
#define stackaslinkedlist_h

#include "rainfall.h"
#include "stack.h"

#include "linkedlist.h"
#include "linkedlist.cpp"

class Rainfall;

class StackAsLinkedList final : public virtual Stack
{
    LinkedList<Rainfall*> list;

    /** The inplementing function in the derived class 
     * Purge() deletes the elements in the container
     */
    void Purge () override;

public:
    /* Constructor and Destructor */
    StackAsLinkedList();
    ~StackAsLinkedList();
    
    /** Inplementing functions in the derived class
     * Top func returns the top object of the Stack.
     * Push func pushes Rainfall object into the Stack.
     * Pop func pops Rainfall object out of the Stack.
     */
    Rainfall& Top () const override;
    void Push (Rainfall&) override;
    void Pop () override;
};

#endif
