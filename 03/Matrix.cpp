#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

Matrix::Matrix() : nrows(0), ncols(0)
{
    mas = nullptr;
}

Matrix::Matrix(size_t nrows, size_t ncols) : nrows(nrows), ncols(ncols)
{
    mas = new int* [nrows];
    for (size_t i=0; i<nrows; i++)
    {
        mas[i] = new int[ncols];
    }
}

Matrix::Matrix(const Matrix& m) : nrows(m.GetRows()), ncols(m.GetCols())
{
    mas = new int* [nrows];
    for (size_t i=0; i<nrows; i++)
    {
        mas[i] = new int[ncols];
        for (size_t j=0; j<ncols; j++)
        {
            mas[i][j] = m.mas[i][j];
        }
    }
}

Matrix::~Matrix()
{
    if (mas)
    {
        for (size_t i=0; i<nrows; i++)
        {
            delete[] mas[i];
        }
        delete[] mas;
    }
}

size_t Matrix::GetCols() const
{
    return ncols;
}

size_t Matrix::GetRows() const
{
    return nrows;
}

Matrix& Matrix::operator *=(int alpha)
{
    for (size_t i=0; i<nrows; i++)
    {
        for (size_t j=0; j<ncols; j++)
        {
            mas[i][j] *= alpha;
        }
    }
    return *this;
}

Matrix Matrix::operator +(const Matrix& m) const
{
    if (nrows == m.GetRows() && ncols == m.GetCols())
    {
        Matrix res = Matrix(nrows, ncols);
        for (size_t i=0; i<nrows; i++)
        {
            for (size_t j=0; j<ncols; j++)
            {
                res.mas[i][j] = mas[i][j] + m.mas[i][j];
            }
        }
        return res;
    }
    else
    {
        return Matrix();
    }
}

bool Matrix::operator ==(const Matrix& m) const
{
    if (nrows != m.GetRows() || ncols != m.GetCols())
    {
        return false;
    }
    bool flag = true;
    for (size_t i=0; i<nrows; i++)
    {
        for (size_t j=0; j<ncols; j++)
        {
            flag = (mas[i][j] == m.mas[i][j]);
            if (flag == false)
            {
                return false;
            }
        }
    }
    return flag;
}

bool Matrix::operator !=(const Matrix& m) const
{
    return !(*this == m);
}

ostream& operator <<(ostream& out, const Matrix& m)
{
    for (size_t i=0; i<m.GetRows(); i++)
    {
        for (size_t j=0; j<m.GetCols(); j++)
        {
            out << m[i][j] << " ";
        }
        out<<endl;
    }
    return out;
}

Vector Matrix::operator [](size_t i) const
{
    if (i < nrows)
    {
        return Vector(mas[i], ncols);
    }
    else
    {
        throw out_of_range("Index is out of dimension!");
    }
}