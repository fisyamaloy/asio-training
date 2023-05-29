#pragma once
#include "Common.hpp"

namespace Network
{

template <class T>
class SafeQueue
{
public:
    SafeQueue()                    = default;
    SafeQueue(const SafeQueue<T>&) = delete;
    virtual ~SafeQueue() { clear(); }

    const T& front() const
    {
        std::scoped_lock lock(mtxQue);
        return que.front();
    }

    const T& back() const
    {
        std::scoped_lock lock(mtxQue);
        return que.back();
    }

    void push_back(const T& item)
    {
        std::scoped_lock lock(mtxQue);
        que.emplace_back(std::move(item));
    }

    void push_front(const T& item)
    {
        std::scoped_lock lock(mtxQue);
        que.emplace_front(std::move(item));
    }

    bool empty() const
    {
        std::scoped_lock lock(mtxQue);
        return que.empty();
    }

    T pop_front()
    {
        std::scoped_lock lock(mtxQue);
        auto item = std::move(que.front());
        que.pop_front();
        return item;
    }

    T pop_back()
    {
        std::scoped_lock lock(mtxQue);
        auto item = std::move(que.back());
        que.pop_back();
        return item;
    }

    void clear()
    {
        std::scoped_lock lock(mtxQue);
        que.clear();
    }

    size_t size() const 
    {
        std::scoped_lock lock(mtxQue);
        return que.size();
    }

    void wait()
    {
        while (empty())
        {
            std::unique_lock<std::mutex> uniqueLock(uniqueMtx);
            mBlock.wait(uniqueLock);
        }
    }

protected:
    mutable std::mutex mtxQue, uniqueMtx;  // TODO: Investigate lock-free queue instead
    std::condition_variable mBlock;
    std::deque<T> que;
};

}  // namespace Network
