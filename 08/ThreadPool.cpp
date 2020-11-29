#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include "ThreadPool.hpp"

using namespace std;

void ThreadPool::work()
{
    // выполняем функцию? 
}

ThreadPool::ThreadPool(size_t size): size(size)
{
    for (size_t i = 0; i < size; i++)
    {
        pool.push_back(this->work());
    }
}