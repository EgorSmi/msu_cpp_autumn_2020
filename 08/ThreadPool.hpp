#pragma once

#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>
#include <atomic>

using namespace std;

using Function = function<void()>;

class ThreadPool
{
private:
    size_t size;
    atomic<bool> alive;
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
        packaged_task<decltype(func(args...))()> task([func, args...]()
        {
            return func(args...);
        });
        auto t = make_shared<packaged_task<decltype(func(args...))()>>(move(task));
        {
            lock_guard<mutex> lock(m);
            thread_q.push([t]()
            {
                (*t)();
            });
        }
        ready.notify_one(); // будим один поток
        return t->get_future();
    }

    ~ThreadPool();
};