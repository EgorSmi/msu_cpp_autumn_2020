template<class T>
class Allocator
{
public:
    using value_type = T;
    using pointer = T*;
    using size_type = size_t;

    pointer allocate(size_type count)
    {
        pointer = new T(count);
        return pointer;
    }
    void deallocate(pointer ptr)
    {
        if (pointer)
        {
            delete pointer();
        }
    }
};