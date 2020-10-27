#pragma once

class MyVector
{
    private:
        size_t n;
        size_t real_n;
        int* vect;
    public:
        MyVector();
        MyVector(size_t n);
        MyVector(const MyVector& v);
        MyVector& operator *=(int alpha);
        MyVector& operator =(const MyVector& v);
        MyVector operator +(const MyVector& v) const;
        bool operator ==(const MyVector& v) const;
        bool operator !=(const MyVector& v) const;
        int& operator [](size_t i);
        const int& operator[](size_t i) const;
        void Clear();
        void Insert(size_t pos, int val);
        void Push_back(int val);
        void Pop_back();
        void Resize(size_t size);
        size_t Size() const;
        bool Empty() const;
        ~MyVector();
};