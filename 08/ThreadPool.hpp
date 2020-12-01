#pragma once

#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>

using namespace std;

using Function = function<void()>;

class ThreadPool
{
private:
    size_t size;
    bool alive;
    thread* pool; // наш пул потоков
    mutex m;
    condition_variable ready;
    queue<Function> thread_q; //очередь из функций -- общий ресурс

    void work();
public:
    explicit ThreadPool(size_t size);

    template <class Func, class... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>
    {
        packaged_task<decltype(func(args...))> task([](Func func, Args... args)
        {
            return func(args...);// связываем функцию с аргументами
        });
        {
            lock_guard<mutex> lock(m);
            thread_q.push(task);
        }
        ready.notify_one(); // будим один поток
        return task.get_future();
    }

    ~ThreadPool();
};