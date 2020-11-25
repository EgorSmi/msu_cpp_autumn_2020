#pragma once

using namespace std;

template <class T>
class Iterator: public iterator<random_access_iterator_tag, T>
{
private:
    T* data;
public:
    using Distance = ptrdiff_t;
    using Pointer = T*;
    using Reference = T&;

    explicit Iterator(): data(nullptr) {}

    explicit Iterator(Pointer data) : data(data) {}

    Reference operator*() const
    {
        return *data;
    }

    Iterator<T>& operator+=(Distance n)
    {
        data += n;
        return *this;
    }

    Iterator<T>& operator-=(Distance n)
    {
        data -= n;
        return *this;
    }

    Iterator<T> operator+(Distance n) const
    {
        return Iterator(data + n);
    }

    Iterator<T> operator-(Distance n) const
    {
        return Iterator(data - n);
    }

    Distance operator-(const Iterator<T> it) const
    {
        return data - it.data;
    }

    Reference operator[](Distance n) const
    {
        return *(data+n);
    }

    Iterator<T>& operator++()
    {
        data++;
        return *this;
    }

    Iterator<T>& operator--()
    {
        data--;
        return *this;
    }

    bool operator==(const Iterator<T>& it) const
    {
        return (*this - it == 0);
    }

    bool operator!=(const Iterator<T>& it) const
    {
        return (*this - it != 0);
    }

    bool operator>(const Iterator<T>& it) const
    {
        return (*this - it > 0);
    }

    bool operator<(const Iterator<T>& it) const
    {
        return (*this - it < 0);
    }

    bool operator>=(const Iterator<T>& it) const
    {
        return (*this - it >= 0);
    }

    bool operator<=(const Iterator<T>& it) const
    {
        return (*this - it <= 0);
    }
};
