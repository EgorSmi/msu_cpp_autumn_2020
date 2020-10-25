#include <iostream>
#include "Matrix.h"

using namespace std;

void DefaultTest()
{
    Matrix m = Matrix(2, 3);
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[1][2] = 6;
    if ((m[0][0] == 1) && (m[0][1] == 2) && (m[0][2] == 3) 
    && (m[1][0] == 4) && (m[1][1] == 5) && (m[1][2] == 6))
    {
        cout<<"OK: Default test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect matrix input"<<endl;
    }
}

void MultiplyTest()
{
    Matrix m = Matrix(2, 3);
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[1][2] = 6;
    m *= 4;
    if ((m[0][0] == 4) && (m[0][1] == 8) && (m[0][2] == 12) 
    && (m[1][0] == 16) && (m[1][1] == 20) && (m[1][2] == 24))
    {
        cout<<"OK: Mutliply test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect matrix multiply"<<endl;
    }
}

void NColumnsTest()
{
    Matrix m = Matrix(34, 12);
    if (m.GetCols() == 12)
    {
        cout<<"OK: Get columns number test"<<endl;
    }
    else
    {
        cout<<"ERROR! Wrong number of columns"<<endl;
    }
}

void NCRowsTest()
{
    Matrix m = Matrix(34, 12);
    if (m.GetRows() == 34)
    {
        cout<<"OK: Get rows number test"<<endl;
    }
    else
    {
        cout<<"ERROR! Wrong number of rows"<<endl;
    }
}

void EqualTest()
{
    Matrix m1 = Matrix(2, 3);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][0] = 4;
    m1[1][1] = 5;
    m1[1][2] = 6;
    Matrix m2 = m1;
    if (m1 == m2)
    {
        cout<<"OK: Equality test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect equality test"<<endl;
    }
}

void InequalTest()
{
    Matrix m1 = Matrix(2, 3);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][0] = 4;
    m1[1][1] = 5;
    m1[1][2] = 6;
    Matrix m2 = Matrix(2, 3);
    m2[0][0] = 1;
    m2[0][1] = 10;
    m2[0][2] = 3;
    m2[1][0] = 4;
    m2[1][1] = 5;
    m2[1][2] = 6;
    if (m1 != m2)
    {
        cout<<"OK: Inequality test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect inequality test"<<endl;
    }
}

void OutOfDimTest()
{
    Matrix m1 = Matrix(2, 3);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][0] = 4;
    m1[1][1] = 5;
    m1[1][2] = 6;
    try
    {
        cout<<m1[2][0]<<endl;
        cout<<"ERROR! Index must be out of dimension"<<endl;
    }
    catch(out_of_range)
    {
        cout<<"OK: Out of dimension test"<<endl;
    }
}

void SumTest()
{
    Matrix m1 = Matrix(2, 3);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][0] = 4;
    m1[1][1] = 5;
    m1[1][2] = 6;
    Matrix m2 = Matrix(2, 3);
    m2[0][0] = 1;
    m2[0][1] = 10;
    m2[0][2] = 3;
    m2[1][0] = 4;
    m2[1][1] = 5;
    m2[1][2] = 6;
    Matrix m3 = m1 + m2;
    if ((m3[0][0] == 2) && (m3[0][1] == 12) && (m3[0][2] == 6) 
    && (m3[1][0] == 8) && (m3[1][1] == 10) && (m3[1][2] == 12))
    {
        cout<<"OK: Summary test"<<endl;
    }
    else
    {
        cout<<"ERROR! Summary test"<<endl;
    }
}

void DifferentSizesTest()
{
    Matrix m1 = Matrix(2, 3);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][0] = 4;
    m1[1][1] = 5;
    m1[1][2] = 6;
    Matrix m2 = Matrix(2, 4);
    Matrix m3 = m1 + m2;
    if (m3 == Matrix())
    {
        cout<<"OK: Different sizes test"<<endl;
    }
    else
    {
        cout<<"ERROR! Different sizes"<<endl;
    }
}

int main()
{
    DefaultTest();
    MultiplyTest();
    NColumnsTest();
    NCRowsTest();
    EqualTest();
    InequalTest();
    OutOfDimTest();
    SumTest();
    DifferentSizesTest();
    return 0;
}