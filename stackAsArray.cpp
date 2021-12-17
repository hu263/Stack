#include "stackAsArray.h"

StackAsArray::StackAsArray (unsigned int size) :
    array (size)
    {}

void StackAsArray::Purge ()
{
	for (unsigned int i = 0; i < count; ++i)
	    delete array [i];
    count = 0;
}

StackAsArray::~StackAsArray ()
    { Purge (); }

void StackAsArray::Push (Rainfall& rainfall)
{
    if (count == array.Length ())
	    throw domain_error ("stack is full");
    array [count++] = &rainfall;
}

void StackAsArray::Pop ()
{
    if (count == 0)
	    throw domain_error ("stack is empty");
    --count;
}

Rainfall& StackAsArray::Top () const
{
    if (count == 0)
	    throw domain_error ("stack is empty");
    return *array [count - 1U];
}