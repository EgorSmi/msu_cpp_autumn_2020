#include "Vector.h"
#pragma once

class Matrix
{
    private:
        int** mas;
        size_t nrows;
        size_t ncols;
    public:
        Matrix(size_t nrows, size_t ncols);
        Matrix(const Matrix& m);
        size_t GetCols() const;
        size_t GetRows() const;
        Matrix& operator *=(int alpha);
        bool operator ==(const Matrix& m) const;
        bool operator !=(const Matrix& m) const;
        Vector operator [](size_t i) const;
        void Read();
        ~Matrix();
};