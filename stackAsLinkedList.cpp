
#include "stackAsLinkedList.h"

StackAsLinkedList::StackAsLinkedList () :
    list ()
    {}

void StackAsLinkedList::Purge ()
{
    list.Purge ();
    count = 0;
}

StackAsLinkedList::~StackAsLinkedList () { Purge (); }

void StackAsLinkedList::Push (Rainfall& rainfall)
{
    list.Prepend (&rainfall);
    ++count;
}

void StackAsLinkedList::Pop ()
{
    if (count == 0)
    {
      throw domain_error ("stack is empty");
    }
    Rainfall& result = *list.First ();
    list.Extract (&result);
    --count;
}

Rainfall& StackAsLinkedList::Top () const
{
    if (count == 0)
      throw domain_error ("stack is empty");
    return *list.First ();
}
