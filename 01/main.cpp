#include <iostream>
#include "Allocator.h"

using namespace std;

void DefaultWorkTest()
{
    char *mas1, *mas2;
    Allocator a;
    a.makeAllocator(sizeof(char)*8);
    mas1 = a.alloc(sizeof(char)*4);
    mas2 = a.alloc(sizeof(char)*4);
    *mas1 = '1';
    *mas2 = '2';
    if ((*mas1 == '1') && (*mas2 == '2'))
    {
        cout<<"OK: Default work test"<<endl;
    }
    else
    {
        cout<<"ERROR! Default work test: work is not correct"<<endl;
    }
}

void NullSizeTest()
{
    char *mas1;
    Allocator a;
    a.makeAllocator(0);
    mas1 = a.alloc(sizeof(char)*4);
    if (mas1 == nullptr)
    {
        cout<<"OK: Null size test"<<endl;
    }
    else
    {
        cout<<"ERROR! Null size test: makeAllocator(0) works incorrectly"<<endl;
    }
}

void DoubleMakeAllocator()
{
    char *mas1, *mas2;
    Allocator a;
    a.makeAllocator(sizeof(char)*8);
    mas1 = a.alloc(sizeof(char)*4);
    mas2 = a.alloc(sizeof(char)*4);
    *mas1 = '1';
    *mas2 = '2';
    a.makeAllocator(sizeof(char)*8);
    mas1 = a.alloc(sizeof(char)*4);
    if (mas1 != nullptr)
    {
        cout<<"OK: Double makeAllocator test"<<endl;;
    }
    else
    {
        cout<<"ERROR! Double makeAllocator test: Using old memory is prohibited"<<endl;
    }
}

void ChangeValueTest()
{
    char *mas1;
    Allocator a;
    a.makeAllocator(sizeof(char)*4);
    mas1 = a.alloc(sizeof(char)*4);
    *mas1 = '1';
    *mas1 = '5';
    if (mas1[0] == '5')
    {
        cout<<"OK: Change value test"<<endl;
    }
    else
    {
        cout<<"ERROR! Change value test: Unable to change a value"<<endl;
    }
}

void ResetTest()
{
    char *mas1, *mas2;
    Allocator a;
    a.makeAllocator(sizeof(char)*8);
    mas1 = a.alloc(sizeof(char)*4);
    mas2 = a.alloc(sizeof(char)*4);
    a.reset();
    mas1 = a.alloc(sizeof(char)*4);
    mas2 = a.alloc(sizeof(char)*4);
    if ((mas1 != nullptr) and (mas2 != nullptr))
    {
        cout<<"OK: Reset test"<<endl;
    }
    else
    {
        cout<<"ERROR! Reset test: Not all memory is available"<<endl;
    }
}

void MemoryLimitTest()
{
    char *mas1;
    Allocator a;
    a.makeAllocator(sizeof(char)*1);
    mas1 = a.alloc(sizeof(char)*2);
    if (mas1 == nullptr)
    {
        cout<<"OK: Memmory limit test - returned value is nullptr"<<endl;
    }
    else
    {
        cout<<"ERROR! Memmory limit test: returned value must be nullptr"<<endl;
    }
}

void AvailableMemoryTest()
{
    char *mas1, *mas2;
    Allocator a;	
    a.makeAllocator(sizeof(char)*4);
    mas1 = a.alloc(sizeof(char)*4);
    *mas1 = '9';
    mas2 = a.alloc(sizeof(char)*1);
    if (mas2 == nullptr)
    {
        cout<<"OK: Available memory test"<<endl;
    }
    else
    {
        cout<<"ERROR! Available memory test: Running out of available memory"<<endl;
    }
}


int main()
{
    // Тест 1
    DefaultWorkTest();
    // Тест 2
    NullSizeTest();
    // Тест 3
    DoubleMakeAllocator();
    // Тест 4
    ChangeValueTest();
    // Тест 5
    ResetTest();
    // Тест 6
    MemoryLimitTest();
    // Тест 7
    AvailableMemoryTest();
    return 0;
}