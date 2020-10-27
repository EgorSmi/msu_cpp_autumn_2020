#include <iostream>
#include "MyVector.h"

using namespace std;

void DefaultTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    if ((v[0] == 1) && (v[1] == 2) && (v[2] == 3) && (v[3] == 4))
    {
        cout<<"OK: Default test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect vector initialization"<<endl;
    }
}

void MultiplyTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v *= 4;
    if ((v[0] == 4) && (v[1] == 8) && (v[2] == 12) && (v[3] == 16))
    {
        cout<<"OK: Mutliply test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect vector multiply"<<endl;
    }
}

void SizeTest()
{
    MyVector v = MyVector(56);
    if (v.Size() == 56)
    {
        cout<<"OK: Size test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect size"<<endl;
    }
}

void AssignTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    MyVector v2 = MyVector(9);
    v2 = v;
    if ((v2[0] == 1) && (v2[1] == 2) && (v2[2] == 3) && (v2[3] == 4))
    {
        cout<<"OK: Assignment test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect vector assignment"<<endl;
    }
}

void DifferentSizesTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    MyVector v2 = MyVector(8);
    MyVector res = v + v2;
    if (res == MyVector())
    {
        cout<<"OK: Different sizes test"<<endl;
    }
    else
    {
        cout<<"ERROR! Terminating with different sizes"<<endl;
    }
}

void SumTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    MyVector v2 = MyVector(4);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;
    v2[3] = 4;
    MyVector res = v + v2;
    if ((res[0] == 2) && (res[1] == 4) && (res[2] == 6) && (res[3] == 8))
    {
        cout<<"OK: Summary test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect vector summary"<<endl;
    }
}

void EqualTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    MyVector v2 = MyVector(4);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;
    v2[3] = 4;
    if (v == v2)
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
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    MyVector v2 = MyVector(4);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 30;
    v2[3] = 4;
    if (v != v2)
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
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    try
    {
        cout<<v[4]<<endl;
        cout<<"ERROR! Index must be out of dimension"<<endl;
    }
    catch(out_of_range)
    {
        cout<<"OK: Out of dimension test"<<endl;
    }
}

void ClearTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v.Clear();
    if (v == MyVector())
    {
        cout<<"OK: Clear test"<<endl;
    }
    else
    {
        cout<<"ERROR! Wrong clear"<<endl;
    }
}

void EmptyTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    MyVector v2 = MyVector(2);
    v2[0] = 1;
    v2[1] = 2;
    v2.Clear();
    if ((v.Empty() == false) && (v2.Empty() == true))
    {
        cout<<"OK: Empty test"<<endl;
    }
    else
    {
        cout<<"ERROR! Empty test"<<endl;
    }
}

void InsertTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v.Insert(2, 10);
    bool flag = ((v[0] == 1) && (v[2] == 10) && (v[1] == 2) && (v[3] == 3) && (v[4] == 4) && (v.Size() == 5));
    v.Insert(0, 0);
    flag &= ((v[0] == 0) && (v[1] == 1) && (v[2] == 2) && (v[3] == 10)  && (v[4] == 3)
    && (v[5] == 4) && (v.Size() == 6));
    if (flag)
    {
        cout<<"OK: Insert test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect insert"<<endl;
    }
}

void PushTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v.Push_back(5);
    if ((v[0] == 1) && (v[1] == 2) && (v[2] == 3) && (v[3] == 4) && (v[4] == 5) && (v.Size() == 5))
    {
        cout<<"OK: Push back test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect push back"<<endl;
    }
}

void PopTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v.Pop_back();
    if ((v[0] == 1) && (v[1] == 2) && (v[2] == 3) && (v.Size() == 3))
    {
        cout<<"OK: Pop back test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect pop back"<<endl;
    }
}

void ResizeTest()
{
    MyVector v = MyVector(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v.Resize(6);
    bool flag = (v.Size() == 6);
    v.Resize(1);
    flag &= ((v.Size() == 1) && (v[0] == 1));
    if (flag)
    {
        cout<<"OK: Resize test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect resize"<<endl;
    } 
}

int main()
{
    DefaultTest();
    MultiplyTest();
    SizeTest();
    AssignTest();
    DifferentSizesTest();
    SumTest();
    EqualTest();
    InequalTest();
    OutOfDimTest();
    ClearTest();
    EmptyTest();
    InsertTest();
    PushTest();
    PopTest();
    ResizeTest();
    return 0;
}