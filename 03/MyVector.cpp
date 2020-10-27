#include <iostream>
#include "MyVector.h"

using namespace std;

MyVector::MyVector() : n(0)
{
    vect = nullptr;
}

MyVector::MyVector(size_t n) : n(n)
{
    vect = (int*)malloc(sizeof(int) * n);
}

MyVector::MyVector(const MyVector& v) : n(v.n)
{
    vect = (int*)malloc(sizeof(int) * n);
    for (size_t i=0; i<n; i++)
    {
        vect[i] = v.vect[i];
    }
}

size_t MyVector::Size() const
{
    return n;
}

MyVector& MyVector::operator*=(int alpha)
{
    for (size_t i=0; i<n; i++)
    {
        vect[i] *= alpha;
    }
    return *this;
}

MyVector& MyVector::operator =(const MyVector& v)
{
    if (vect)
    {
        free(vect);
    }
    n = v.Size();
    vect = (int*)malloc(sizeof(int) * n);
    for (size_t i=0; i<n; i++)
    {
        vect[i] = v.vect[i];
    }
    return *this;
}

MyVector MyVector::operator +(const MyVector& v) const
{
    if (n == v.Size())
    {
        MyVector res = MyVector(n);
        for (size_t i=0; i<n; i++)
        {
            res.vect[i] = vect[i] + v.vect[i];
        }
        return res;
    }
    else
    {
        return MyVector();
    }
}

bool MyVector::operator==(const MyVector& v) const
{
    if (n != v.Size())
    {
        return false;
    }
    bool flag = true;
    for (size_t i=0; i<n; i++)
    {
        flag = (vect[i] == v.vect[i]);
        if (flag == false)
        {
            return false;
        }
    }
    return true;
}

bool MyVector::operator!=(const MyVector& v) const
{
    return !(*this == v);
}

int& MyVector::operator[](size_t i) const
{
    if (i < n)
    {
        return vect[i];
    }
    else
    {
        throw out_of_range("Index is out of dimension!");
    }
}

void MyVector::Clear()
{
    if (vect)
    {
        free(vect);
    }
    vect = nullptr;
    n = 0;
}

bool MyVector::Empty() const
{
    if (n == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MyVector::Insert(size_t pos, int val)
{
    if (pos <= n)
    {
        int tmp[n];
        for (size_t i=0; i<n; i++)
        {
            tmp[i] = vect[i];
        }
        free(vect);
        n = n + 1;
        vect = (int*) malloc(sizeof(int) * n);
        for (size_t i=0; i<n; i++)
        {
            if (i > pos)
            {
                vect[i] = tmp[i - 1];
            }
            else
            {
                if (i != pos)
                {
                    vect[i] = tmp[i];
                }
                else
                {
                    vect[i] = val;
                }
            }
        }
    }
    else
    {
        throw out_of_range("Index is out of dimension!");
    }
}

void MyVector::Push_back(int val)
{
    int tmp[n];
    for (size_t i=0; i<n; i++)
    {
        tmp[i] = vect[i];
    }
    free(vect);
    n = n + 1;
    vect = (int*) malloc(sizeof(int) * n);
    for (size_t i=0; i<n-1; i++)
    {
        vect[i] = tmp[i];
    }
    vect[n-1] = val;
}

void MyVector::Pop_back()
{
    if (n > 0)
    {
        int tmp[n];
        for (size_t i=0; i<n; i++)
        {
            tmp[i] = vect[i];
        }
        free(vect);
        n = n - 1;
        vect = (int*) malloc(sizeof(int) * n);
        for (size_t i=0; i<n; i++)
        {
            vect[i] = tmp[i];
        }
    }
    else
    {
        throw out_of_range("Vector is empty!");
    }
}

void MyVector::Resize(size_t size)
{
    if (size >= n)
    {
        n = size;
        vect = (int*) realloc(vect, sizeof(int) * (n+1));
    }
    else
    {
        int tmp[n];
        for (size_t i=0; i<n; i++)
        {
            tmp[i] = vect[i];
        }
        free(vect);
        n = size;
        vect = (int*) malloc(sizeof(int) * n);
        for (size_t i=0; i<n; i++)
        {
            vect[i] = tmp[i];
        }
    }
}

MyVector::~MyVector()
{
    if (vect)
    {
        free(vect);
    }
}