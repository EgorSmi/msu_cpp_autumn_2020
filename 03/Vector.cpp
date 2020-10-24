#include <iostream>
#include "Vector.h"

using namespace std;

Vector::Vector(int* vect, size_t n) : n(n)
{
    this->vector = vect;
}

int& Vector::operator [](size_t i) const
{
    if (i < n)
    {
        return vector[i];
    }
    else
    {
        throw out_of_range("Index is out of dimension!");
    }
}