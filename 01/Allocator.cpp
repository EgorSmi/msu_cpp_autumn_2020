#include <cstdio>
#include <unistd.h>
#include <cstddef>
#include <iostream>
#include "Allocator.h"

using namespace std;

void Allocator::makeAllocator(size_t maxSize)
{
    start = new char[maxSize];
    cur = start;
    Max = maxSize;
}

char* Allocator:: alloc(size_t size)
{
    if (size > 0)
    {
        if (start+Max-cur >= size)
        {
            cur += size;
            return cur - size;
        }
        else
        {
            cout<<"Нет места"<<endl;
            return nullptr;
        }
    }
    else
    {
        cout<<"Size <= 0"<<endl;
        return nullptr;
    }
}

void Allocator::reset()
{
    cur = 0;
    Max = 0;
    delete[] start;
}