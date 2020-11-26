#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include "ThreadPool.hpp"

using namespace std;

ThreadPool::ThreadPool(size_t poolSize): poolSize(poolSize)
{

}