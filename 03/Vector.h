#pragma once

class Vector
{
    private:
        int* vector;
        size_t n;
    public:
        Vector(int* vect, size_t n);
        int& operator [](size_t i) const;
};