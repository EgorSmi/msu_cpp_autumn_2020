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
    vector<thread> pool;
    mutex m;
    condition_variable ready;
    queue<Function> thread_q;
    void work();
public:
    explicit ThreadPool(size_t size);

    template <class Func, class... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>
    {
        return 0;
    }
    ~ThreadPool();
};