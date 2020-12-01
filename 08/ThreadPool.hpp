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
    thread* pool; // наш пул потоков
    mutex m;
    condition_variable ready;
    queue<Function> thread_q; //очередь из функций -- общий ресурс
public:
    explicit ThreadPool(size_t size);
    template <class Func, class... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>
    {
        return 0;
    }
    ~ThreadPool();
};