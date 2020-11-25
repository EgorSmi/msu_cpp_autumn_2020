#pragma once

#include <iostream>
#include <algorithm>
#include "Iterator.hpp"
#include "Allocator.hpp"

using namespace std;

template<class T,
    class Alloc = Allocator<T>>
class Vector
{
public:
    using size_type = size_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using const_reference = const T&;
	using allocator_type = Alloc;
    using iterator = Iterator<T>;
    using reverse_iterator = reverse_iterator<Iterator<T>>;
    using difference = ptrdiff_t;

private:
    allocator_type allocator;
    size_type size;
    size_type capacity;
    pointer data;
public:
    explicit Vector(): size(0), capacity(0), data(allocator.allocate(0)) {}

    Vector(size_type size): size(size), capacity(2 * size), data(allocator.allocate(capacity)) {}

    Vector(const Vector& v): size(v.size), capacity(v.capacity), data(allocator.allocate(capacity))
    {
        for (size_type i=0; i<v.size; i++)
        {
            data[i] = v.data[i];
        }
    }

    Vector operator=(const Vector& v)
    {
        if (*this != v)
        {
            if (data)
            {
                allocator.deallocate(data);
            }
            size = v.size;
            capacity = v.capacity;
            data = allocator.allocate(capacity);
            for (size_type i=0; i<v.size; i++)
            {
                data[i] = v.data[i];
            }
        }
        return *this;
    }

    bool operator==(const Vector& v) const
    {
        if (size != v.Size())
        {
            return false;
        }
        bool flag = true;
        for (size_type i=0; i<size; i++)
        {
            flag = (data[i] == v.data[i]);
            if (flag == false)
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector& v) const
    {
        return !(*this == v);
    }

    size_type Size() const
    {
        return size;
    }

    size_type Capacity() const
    {
        return capacity;
    }

    reference operator[](difference i)
    {
        if (i < size)
        {
            return data[i];
        }
        else
        {
            throw out_of_range("Index is out of dimension!");
        }
    }

    const_reference operator[](difference i) const
    {
        if (i < size)
        {
            return data[i];
        }
        else
        {
            throw out_of_range("Index is out of dimension!");
        }
    }

    void Clear()
    {
        if (data)
        {
            allocator.deallocate(data);
        }
        data = nullptr;
        size = 0;
    }

    bool Empty() const
    {
        return (size == 0);
    }

    void Reserve(size_type n)
    {
        if (n > capacity)
        {
            capacity = n;
        }
    }

    void Push_back(const_reference val)
    {
        if (size == capacity)
        {
            value_type tmp[size];
            for (size_type i=0; i<size; i++)
            {
                tmp[i] = data[i];
            }
            allocator.deallocate(data);
            size++;
            capacity *= 2;
            data = allocator.allocate(capacity);
            for (size_type i=0; i<size-1; i++)
            {
                data[i] = tmp[i];
            }
            data[size-1] = val;
        }
        else
        {
            size++;
            data[size-1] = val;
        }
    }

    void Pop_back()
    {
        if (size > 0)
        {
            this->Resize(size-1);
        }
        else
        {
            throw out_of_range("Vector is empty!");
        }
    }

    template<class... Args>
    void Emplace_back(Args&&... args)
    {
        this->Push_back(value_type(forward<Args>(args)...));
    }

    void Resize(size_type n)
    {
        value_type tmp[size];
        for (size_type i=0; i<size; i++)
        {
            tmp[i] = data[i];
        }
        allocator.deallocate(data);
        size = n;
        capacity = size * 2;
        data = allocator.allocate(capacity);
        for (size_type i=0; i<size; i++)
        {
            data[i] = tmp[i];
        }
    }

    iterator begin() const
    {
        return Iterator<value_type>(data);
    }

    iterator end() const
    {
        return Iterator<value_type>(data + size);
    }

    reverse_iterator rbegin() const
    {
        return reverse_iterator(Iterator<value_type>(data + size));
    }

    reverse_iterator rend() const
    {
        return reverse_iterator(Iterator<value_type>(data));
    }

    ~Vector()
    {
        if (data)
        {
            allocator.deallocate(data);
        }
    }
};