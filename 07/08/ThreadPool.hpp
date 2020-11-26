#pragma once

#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>

using namespace std;

class ThreadPool
{
private:
    size_t size;
    vector<thread> pool;
    mutex m;
    condition_variable ready;
    queue<thread> thread_q;
public:
    explicit ThreadPool(size_t poolSize);

    template <class Func, class... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>
    {
        return 0;
    }
    ~ThreadPool();
};