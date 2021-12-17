#ifndef array_h
#define array_h

template <class T>
class Array
{
protected:
    T* data;
    unsigned int base;
    unsigned int length;
public:
    Array ();
    Array (unsigned int, unsigned int = 0);
    ~Array ();

    Array (Array const&);
    Array& operator = (Array const&);

    T const& operator [] (unsigned int) const;
    T& operator [] (unsigned int);

    T const* Data () const;
    unsigned int Base () const;
    unsigned int Length () const;

    void SetBase (unsigned int);
    void SetLength (unsigned int);
};

#endif