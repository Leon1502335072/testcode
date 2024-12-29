#include<iostream>
#include "threadpool.h"
using namespace std;

ThreadPool::ThreadPool(int min, int max)
                    :m_minThreads(min)
                    ,m_maxThreads(max)
                    ,m_stop(false)
                    ,m_exitNumber(0)

{
    m_idleThreads = min;
    m_curThreads = min;
    cout << "当前工作线程数量: " << m_curThreads << endl;
    cout << "最大工作线程数量: " << m_maxThreads << endl;
    // 创建管理者线程
    m_manager = new thread(&ThreadPool::manager, this);
    // 创建工作线程
    for (int i = 0; i < m_curThreads; ++i)
    {
        thread t(&ThreadPool::worker, this);
        m_workers.insert(make_pair(t.get_id(), move(t)));
    }
}

ThreadPool::~ThreadPool()
{
    m_stop = true;
    m_condition.notify_all();
    for(auto& [t_id, t] : m_workers)
    {
        if (t.joinable())
        {
            cout << "******** 线程 " << t.get_id() << " 将要退出了..." << endl;
            t.join();
        }
    }

    if(m_manager->joinable())
    {
        m_manager->join();
    }
    delete m_manager;
}
void ThreadPool::addtask(function<void()> f)
{
    {
        lock_guard<mutex> locker(m_taskMutex);
        m_tasks.emplace(f);
    }
    // 通知
    m_condition.notify_one();
}

void ThreadPool::manager()
{
    // 只要线程池不停就一直检测
    while(!m_stop.load())
    {
        // 每两秒钟检测一次
        this_thread::sleep_for(chrono::seconds(3));
        int idle = m_idleThreads.load();
        int current = m_curThreads.load();

        if (idle > m_maxThreads / 2 && current > m_minThreads)
        {
            // 退出线程数设置为2
            m_exitNumber.store(2);
            m_condition.notify_all();

            // 这个睡眠主要是用来演示在manager中回收结束的线程的资源
            this_thread::sleep_for(chrono::seconds(2));

            unique_lock<mutex> lck(m_idsMutex);
            for(auto& id : m_ids)
            {
                auto it = m_workers.find(id);
                if(it != m_workers.end())
                {
                    cout << "############## 线程 " << (*it).first << "被销毁了...." << endl;
                    (*it).second.join();
                    m_workers.erase(it);
                }
            }
            m_ids.clear();
        }
        else if(idle == 0 && current < m_maxThreads)
        {
            // 创建新的线程
            thread t(&ThreadPool::worker, this);
            cout << "+++++++++++++++ 添加了一个线程, id: " << t.get_id() << endl;
            m_workers.insert(make_pair(t.get_id(), move(t)));
            m_curThreads++;
            m_idleThreads++;
        }
    }
}
void ThreadPool::worker()
{
    while(!m_stop.load())
    {
        function<void()> task = nullptr;
        {
            unique_lock<mutex> lock(m_taskMutex);
            while (m_tasks.empty() && !m_stop.load())
            {
                // 所有线程阻塞在这里
                m_condition.wait(lock);
                // 线程被唤醒 查看m_exitNumber的值
                if(m_exitNumber > 0)
                {
                    cout << "----------------- 线程任务结束, ID: " << this_thread::get_id() << endl;
                    m_exitNumber--;
                    m_idleThreads--;
                    m_curThreads--;
                    m_idsMutex.lock();
                    m_ids.emplace_back(this_thread::get_id());
                    m_idsMutex.unlock();
                    // 该线程执行结束
                    return;
                }
            }

            // 队列不为空
            if(!m_tasks.empty())
            {
                cout << "取出一个任务..." << endl;
                task = move(m_tasks.front());
                m_tasks.pop();
            }
        }

        // 执行任务
        if(task)
        {
            m_idleThreads--;
            task();
            m_idleThreads++;
        }
    }
}

void calc(int a, int b)
{
    int z = a + b;
    cout << "res = " << z << endl;
    this_thread::sleep_for(chrono::seconds(2));
}

int calc1(int a, int b)
{
    int z = a + b;
    this_thread::sleep_for(chrono::seconds(2));
    return z;
}

int main(int arg, char* argv[])
{
    ThreadPool pool;
    vector<future<int>> results;
    for (int i = 0; i < 10; ++i)
    {
        results.emplace_back(pool.addtask(calc1, i, i * 2));
    }

    for (auto& futr : results)
    {
        cout << "线程函数返回值: " << futr.get() << endl;
    }

    return 0;
}