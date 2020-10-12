#pragma once
#include <iostream>

using namespace std;

class Allocator
{
    private:
        char* start;
        char* cur;
        int Max;
    public:
        Allocator();
        void makeAllocator(size_t maxSize);
        char* alloc(size_t size);
        void reset();
        ~Allocator();
};
