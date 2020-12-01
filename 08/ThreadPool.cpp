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
            { // поток работает постоянно, пока он жив
                unique_lock<mutex> lock(m);
                if (thread_q.empty() == false)
                {
                    // вход в критическую секцию
                    lock.lock();
                    auto func = thread_q.front();
                    thread_q.pop();
                    lock.unlock();
                    // выход из критической секции
                    func(); 
                }
                else
                {
                    // ждем функцию на выполнение
                    ready.wait(lock);
                }
            }
        };
        pool[i] = thread(move(work));
    }
}



ThreadPool::~ThreadPool()
{
    ready.notify_all();
    for (size_t i=0; i<size; i++)
    {
        pool[i].join(); // ждем завершение всех потоков
    }
    delete[] pool;
}