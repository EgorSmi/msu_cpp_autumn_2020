#ifndef ALLOCATOR
#define ALLOCATOR

#include <cstdio>
#include <unistd.h>
#include <cstddef>
#include <iostream>

using namespace std;

class Allocator
{
    private:
    char* start;
    char* cur;
    int Max;
    public:
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    ~Allocator();
};

#endif