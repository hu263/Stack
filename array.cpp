#include "array.h"

#include <stdexcept>
using namespace std;

template <class T>
Array<T>::Array () :
    data (new T [0]),
    base (0),
    length (0)
    {}

template <class T>
Array<T>::Array (unsigned int n, unsigned int m) :
    data (new T [n]),
    base (m),
    length (n)
    {}

template <class T>
Array<T>::Array (Array<T> const& array) :
    data (new T [array.length]),
    base (array.base),
    length (array.length)
{
    for (unsigned int i = 0; i < length; ++i)
	    data [i] = array.data [i];
}

template <class T>
Array<T>& Array<T>::operator = (Array<T> const& array)
{
    data = new T [array.length],
    base = array.base,
    length = array.length;
    for (unsigned int i = 0; i < length; ++i)
	    data [i] = array.data [i];
    return *this;
}

template <class T>
Array<T>::~Array ()
    { delete [] data; }

template <class T>
T const* Array<T>::Data () const
    { return data; }

template <class T>
unsigned int Array<T>::Base () const
    { return base; }

template <class T>
unsigned int Array<T>::Length () const
    { return length; }

template <class T>
T const& Array<T>::operator [] (unsigned int position) const
{
    unsigned int const offset = position - base;
    if (offset >= length)
	    throw out_of_range ("invalid position");
    return data [offset];
}

template <class T>
T& Array<T>::operator [] (unsigned int position)
{
    unsigned int const offset = position - base;
    if (offset >= length)
	    throw out_of_range ("invalid position");
    return data [offset];
}

template <class T>
void Array<T>::SetBase (unsigned int newBase)
    { base = newBase; }

template <class T>
void Array<T>::SetLength (unsigned int newLength)
{
    T* const newData = new T [newLength];
    unsigned int const min =
	length < newLength ? length : newLength;
    for (unsigned int i = 0; i < min; ++i)
	newData [i] = data [i];
    delete [] data;
    data = newData;
    length = newLength;
}