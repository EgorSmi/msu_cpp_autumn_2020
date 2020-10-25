#pragma once
#include <iostream>
#include "Vector.h"

using namespace std;

class Matrix
{
    private:
        int** mas;
        size_t nrows;
        size_t ncols;
    public:
        Matrix();
        Matrix(size_t nrows, size_t ncols);
        Matrix(const Matrix& m);
        size_t GetCols() const;
        size_t GetRows() const;
        Matrix& operator *=(int alpha);
        Matrix operator +(const Matrix& m) const;
        bool operator ==(const Matrix& m) const;
        bool operator !=(const Matrix& m) const;
        Vector operator [](size_t i) const;
        friend ostream& operator <<(ostream& out, const Matrix& m);
        ~Matrix();
};