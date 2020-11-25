#pragma once

template<class T>
class Allocator
{
public:
    using value_type = T;
    using pointer = T*;
    using size_type = size_t;

    pointer allocate(size_type count)
    {
        pointer ptr = static_cast<pointer>(::operator new(count));
        return ptr;
    }

    void deallocate(pointer ptr)
    {
        if (ptr)
        {
            ::operator delete(ptr);
        }
    }
};