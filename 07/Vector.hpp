#pragma once

#include <iostream>
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
    using rvalue_type = T&&;
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

    Vector(Vector&& v): size(v.size), capacity(v.capacity), data(v.data)
    {
        v.size = 0;
        v.capacity = 0;
        v.data = nullptr;
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

    Vector operator=(Vector&& v)
    {
        if (*this != v)
        {
            if (data)
            {
                allocator.deallocate(data);
            }
            size = v.size;
            capacity = v.capacity;
            data = v.data;
            v.size = 0;
            v.capacity = 0;
            v.data = nullptr;
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

    reference operator[](size_type i)
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

    const_reference operator[](size_type i) const
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
            pointer tmp = allocator.allocate(capacity);
            tmp = move(data);
            allocator.deallocate(data);
            data = allocator.allocate(capacity);
            data = move(tmp);
        }
    }

    void Push_back(const_reference val)
    {
        if (size == capacity)
        {
            this->Reserve(2 * capacity);
        }
        data[size++] = val;
    }

    void Push_back(rvalue_type val)
    {
        if (size == capacity)
        {
            this->Resize(2 * capacity);
        }
        data[size++] = move(val);
    }

    void Pop_back()
    {
        if (size > 0)
        {
            size--;
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
        if (n > size)
        {
            this->Reserve(2 * n);
        }
        size = n;
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