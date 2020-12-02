#include <iostream>
#include "ThreadPool.hpp"

void foo()
{
    cout<<"1"<<endl;
}

void DefaultWorkTest()
{
    ThreadPool pool = ThreadPool(2);
    auto task = pool.exec(foo);
    task.get();
}

int main()
{
    DefaultWorkTest();
    return 0;
}