#include <iostream>
#include "Iterator.hpp"
#include "Allocator.hpp"

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

int main()
{
    IteratorTest();
    IterationTest();
    DistanceTest();
    ComparisonsTest();
    return 0;
}