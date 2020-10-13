#include <iostream>
#include "Allocator.h"

using namespace std;

Allocator::Allocator()
{
    start = nullptr;
    cur = nullptr;
    Max = 0;
}

void Allocator::makeAllocator(size_t maxSize)
{
    if (start)
    {
        cout<<"Delete[] for old memory"<<endl;
        delete[] start;
    }
    if (maxSize == 0)
    {
        cout << "Size must be positive" << endl;
    }
    else
    {
        start = new char[maxSize];
        cur = start;
        Max = maxSize;
    }
}

char* Allocator:: alloc(size_t size)
{
    if (start+Max-cur >= size)
    {
        cur += size;
        return cur - size;
    }
    else
    {
        cout<<"Not enough memory for alloc"<<endl;
        return nullptr;
    }
}

void Allocator::reset()
{
    cur = start;
}

Allocator::~Allocator()
{
    if (start)
    {
        delete[] start;
    }
}