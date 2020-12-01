#include <iostream>
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
    while (alive)
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
            try
            {
                func(); 
            }
            catch(...)
            {
                cout<<"Error in the thread "<<this_thread::get_id()<<endl;
                this_thread::yield(); // отдать квант времени процессору и вернуться к выполнению в следующий раз
            }
        }
        else
        {
            // ждем функцию на выполнение
            ready.wait(lock);
        }
    }
}

ThreadPool::ThreadPool(size_t size): size(size), alive(true)
{
    pool = new thread[size];
    for (size_t i = 0; i < size; i++)
    {
        pool[i] = thread(&ThreadPool::work, this);
    }
}

ThreadPool::~ThreadPool()
{
    alive = false;
    ready.notify_all(); // будим потоки, чтобы их удалить
    for (size_t i=0; i<size; i++)
    {
        pool[i].join(); // ждем завершение всех потоков
    }
    delete[] pool;
}