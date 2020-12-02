#include <iostream>
#include "ThreadPool.hpp"


void DefaultWorkTest()
{
    ThreadPool pool = ThreadPool(8);
    auto task = pool.exec([]()
    {
        return 1;
    });
    if (task.get() == 1)
    {
        cout<<"OK! Default work test"<<endl;
    }
    else
    {
        cout<<"ERROR! Default work test"<<endl;
    }
}

void TwoThreadsTest()
{
    ThreadPool pool = ThreadPool(2);
    auto task1 = pool.exec([]()
    {
        return 1;
    });
    auto task2 = pool.exec([]()
    {
        return 2;
    });
    if ((task1.get() == 1) && (task2.get() == 2))
    {
        cout<<"OK! Two threads test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect work"<<endl;
    }
}

int main()
{
    DefaultWorkTest();
    TwoThreadsTest();
    return 0;
}