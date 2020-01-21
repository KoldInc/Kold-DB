#ifndef KOLD_DB_WAIT_QUEUE
#define KOLD_DB_WAIT_QUEUE

#include <chrono>
#include <queue>
#include <mutex>
#include <condition_variable>

#include "queue.hpp"


// to be implmented #include "task.hpp"
typedef int Task;

using STDQueue = std::queue<Task>;

class WaitQueue: public IQueue<Task>
{
public:
        WaitQueue();
        ~WaitQueue();

        Task Push(const Task& task);
        Task& Pop();
        Task& TimedPop(std::chrono::milliseconds timeout);
  
private:
        WaitQueue(const WaitQueue& other);
        WaitQueue& operator=(const WaitQueue& other);

        STDQueue m_queue;
        std::mutex m_lock;
        std::condition_variable m_queueNotEmpty;
};

#endif // KOLD_DB_WAIT_QUEUE
