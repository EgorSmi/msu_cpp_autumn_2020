#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include "ThreadPool.hpp"

using namespace std;

ThreadPool::ThreadPool(size_t size): size(size)
{
    pool = new thread[size];
    for (size_t i = 0; i < size; i++)
    {
        auto work = [this]()
        {
            while (true)
            {
                {
                    lock_guard<mutex> lock(m);
                    // вход в критическую секцию
                    if (thread_q.empty() == false)
                    {
                        auto func = thread_q.front();
                        thread_q.pop();
                        func();
                    }
                    else
                    {
                        // ждем функцию на выполнение
                        ready.wait(lock);
                    }
                }
            }
        };
        pool[i] = thread(move(work));
        pool[i].detach();
    }
}

