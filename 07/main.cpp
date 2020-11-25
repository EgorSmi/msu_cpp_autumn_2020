#include <iostream>
#include "Iterator.hpp"
#include "Allocator.hpp"
#include "Vector.hpp"

using namespace std;

void IteratorTest()
{
    int* mas = new int(5);
    for (size_t i = 0; i<5; i++)
    {
        mas[i] = i + 50;
    }
    Iterator<int> it = Iterator<int>(mas);
    if (it[0] == 50)
    {
        cout<<"OK: Iterator test"<<endl;
    }
    else
    {
        cout<<"ERROR! Iterator test"<<endl;
    }
}

void IterationTest()
{
    int* mas = new int(5);
    for (size_t i = 0; i<5; i++)
    {
        mas[i] = i + 50;
    }
    Iterator<int> it = Iterator<int>(mas);
    it+=2;
    if ((it[0] == 52) && (it[1] == 53) && (it[2] == 54))
    {
        cout<<"OK: Iteration test"<<endl;
    }
    else
    {
        cout<<"ERROR! Wrong iteration"<<endl;
    }
}

void DistanceTest()
{
    int* mas = new int(5);
    for (size_t i = 0; i<5; i++)
    {
        mas[i] = i + 50;
    }
    Iterator<int> it1 = Iterator<int>(mas);
    Iterator<int> it2 = Iterator<int>(mas+2);
    if (it2 - it1 == 2)
    {
        cout<<"OK: Distance test"<<endl;
    }
    else
    {
        cout<<"ERROR! Wrong distance"<<endl;
    }
}

void ComparisonsTest()
{
    int* mas = new int(5);
    for (size_t i = 0; i<5; i++)
    {
        mas[i] = i + 50;
    }
    Iterator<int> it1 = Iterator<int>(mas);
    Iterator<int> it2 = Iterator<int>(mas+2);
    if ((it1 < it2) && (it1 != it2))
    {
        cout<<"OK: Comparisons test"<<endl;
    }
    else
    {
        cout<<"ERROR! Wrong comparisons"<<endl;
    }
}

void DefaultTest()
{
    Vector<int> v = Vector<int>(4);
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

void SizeTest()
{
    Vector<int> v = Vector<int>(56);
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
    Vector<int> v = Vector<int>(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    Vector<int> v2 = Vector<int>(9);
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

void EqualTest()
{
    Vector<int> v = Vector<int>(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    Vector<int> v2 = Vector<int>(4);
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
    Vector<int> v = Vector<int>(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    Vector<int> v2 = Vector<int>(4);
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
    Vector<int> v = Vector<int>(4);
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
    Vector<int> v = Vector<int>(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v.Clear();
    if (v == Vector<int>())
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
    Vector<int> v = Vector<int>(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    Vector<int> v2 = Vector<int>(2);
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

void PushTest()
{
    Vector<int> v = Vector<int>(4);
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

void EmplaceTest()
{
    struct Item
    {
        int a, b, c;
        Item(int a, int b, int c): a(a), b(b), c(c) {}
    };
    Vector<Item> v;
    v.Emplace_back(1, 2, 3);
    if ((v[0].a == 1) && (v[0].b == 2) && (v[0].c == 3))
    {
        cout<<"OK: Emplace back test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect emplace back"<<endl;
    }
}

void PopTest()
{
    Vector<int> v = Vector<int>(4);
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
    Vector<int> v = Vector<int>(4);
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

void ReserveTest()
{
    Vector<int> v = Vector<int>(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v.Reserve(6);
    bool flag = (v.Capacity() == 8);
    v.Reserve(1);
    flag &= (v.Capacity() == 8);
    if (flag)
    {
        cout<<"OK: Reserve test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect reserve"<<endl;
    } 
}

int main()
{
    IteratorTest();
    IterationTest();
    DistanceTest();
    ComparisonsTest();
    DefaultTest();
    SizeTest();
    AssignTest();
    EqualTest();
    InequalTest();
    OutOfDimTest();
    ClearTest();
    EmptyTest();
    PushTest();
    EmplaceTest();
    PopTest();
    ResizeTest();
    ReserveTest();
    return 0;
}