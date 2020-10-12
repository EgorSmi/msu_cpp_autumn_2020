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
        cout<<"Выполнен delete[] для старых данных"<<endl;
        delete[] start;
    }
    if (maxSize == 0)
    {
        cout << "Размер должен быть положительный" << endl;
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
        cout<<"Нет места"<<endl;
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
        cout<<"Вызов деструктора"<<endl;
        delete[] start;
    }
}