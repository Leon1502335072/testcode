#include <iostream>
#include <queue>
#include <condition_variable>
#include <thread>
#include <mutex>
using namespace std;
using namespace chrono;

#if 0
class TaskQueue
{
public:
    void put(const int& task)
    {
        // 加锁
        unique_lock<mutex> lock(myMutex);
        while (taskqueue.size() == maxSize)
        {
            // 当线程进来时说明任务队列已经满了条件变量的wait方法会使得该线程先释放锁 然后将该线程阻塞起来 并不会一直持有锁
            notfull.wait(lock);
        }
        taskqueue.push(task);
        cout << "添加任务 " << task << " 成功! thread Id = " << this_thread::get_id() << endl;
        // 唤醒消费者
        notempty.notify_one();
    }

    void take()
    {
        unique_lock<mutex> lock(myMutex);
        while(taskqueue.empty())
        {
            notempty.wait(lock);
        }
        int node = taskqueue.front();
        taskqueue.pop();
        cout << "获取任务 " << node << " 成功! thread Id = " << this_thread::get_id() << endl;
        // 唤醒生产者线程
        notfull.notify_all();
    }

    bool isFull()
    {
        lock_guard<mutex> lock(myMutex);
        if (taskqueue.size() == maxSize)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        lock_guard<mutex> lock(myMutex);
        if (taskqueue.empty())
        {
            return true;
        }
        return false;
    }

private:
    int maxSize = 100;
    queue<int> taskqueue;
    condition_variable notfull;
    condition_variable notempty;
    mutex myMutex;
};
#endif

#if 0
class TaskQueue
{
public:
    void put(const int& task)
    {
        // 加锁
        unique_lock<mutex> lock(myMutex);
        // 当线程进来时说明任务队列已经满了条件变量的wait方法会使得该线程先释放锁 然后将该线程阻塞起来 并不会一直持有锁
        notfull.wait(lock, [=]()
                        { return !(taskqueue.size() == maxSize); }); // wait第二个参数的匿名函数如果返回true 则不会阻塞线程
        taskqueue.push(task);
        cout << "添加任务 " << task << " 成功! thread Id = " << this_thread::get_id() << endl;
        // 唤醒消费者
        notempty.notify_one();
    }

    void take()
    {
        unique_lock<mutex> lock(myMutex);
        notempty.wait(lock, [=]()
                    { return !taskqueue.empty(); });
        int node = taskqueue.front();
        taskqueue.pop();
        cout << "获取任务 " << node << " 成功! thread Id = " << this_thread::get_id() << endl;
        // 唤醒生产者线程
        notfull.notify_all();
    }

    bool isFull()
    {
        lock_guard<mutex> lock(myMutex);
        if (taskqueue.size() == maxSize)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        lock_guard<mutex> lock(myMutex);
        if (taskqueue.empty())
        {
            return true;
        }
        return false;
    }

private:
    int maxSize = 100;
    queue<int> taskqueue;
    condition_variable notfull;
    condition_variable notempty;
    mutex myMutex;
};
#endif

class TaskQueue
{
public:
    // 添加数据
    void put(const int& task)
    {
        lock_guard<mutex> locker(myMutex);
        while (taskQueue.size() == maxSize)
        {
            notFull.wait(myMutex);
        }
        taskQueue.push(task);
        cout << "添加任务: " << task << ", 线程ID: " << this_thread::get_id() << endl;
        // 唤醒消费者
        notEmpty.notify_one();
    }

    // 取数据
    void take()
    {
        myMutex.lock();
        notEmpty.wait(myMutex, [=]() {
            return !taskQueue.empty();
            });

        int node = taskQueue.front();
        taskQueue.pop();
        cout << "删除任务: " << node << ", 线程ID: " << this_thread::get_id() << endl;
        myMutex.unlock();
        // 唤醒生产者
        notFull.notify_all();
    }

    bool isFull()
    {
        lock_guard<mutex> locker(myMutex);
        if (maxSize == taskQueue.size())
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        lock_guard<mutex> locker(myMutex);
        if (taskQueue.size() == 0)
        {
            return true;
        }
        return false;
    }

    int taskSize()
    {
        lock_guard<mutex> locker(myMutex);
        return taskQueue.size();
    }
private:
    int maxSize = 100;
    queue<int> taskQueue;
    mutex myMutex;
    condition_variable_any notFull;     // 生产者
    condition_variable_any notEmpty;    // 消费者
};


int main(int arg, char* argv[])
{
    thread t1[5];  // 生产者
    thread t2[5];  // 消费者
    TaskQueue taskQ;
    for (int i = 0; i < 5; ++i)
    {
        t1[i] = thread(&TaskQueue::put, &taskQ, 100 + i);
        t2[i] = thread(&TaskQueue::take, &taskQ);
    }

    for (int i = 0; i < 5; ++i)
    {
        t1[i].join();
        t2[i].join();
    }


    return 0;
}