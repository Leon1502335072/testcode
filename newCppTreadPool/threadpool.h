#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__
#include <thread>
#include <mutex>
#include <map>
#include <vector>
#include <condition_variable>
#include <queue>
#include <atomic>
#include <functional>
#include <future>
#include <memory>
using namespace std;


class ThreadPool
{
public:
    // ThreadPool(int min = 2, int max = thread::hardware_concurrency());
    ThreadPool(int min = 2, int max = 16);
    
    ~ThreadPool();
    //添加任务
    void addtask(function<void()> f); 
    
    template<class F, class... Args>
    // addtask的返回值是future类型，future的模版参数类型就应该是F类型函数的返回值类型 
    // F类型的函数的返回值类型通过 result_of 来拿到
    auto addtask(F&& f, Args&&... args) -> future<typename result_of<F(Args...)>::type>
    {
        using returnType = typename result_of<F(Args...)>::type;
        // 用一个智能指针管理packaged_task对象
        auto task = make_shared<packaged_task<returnType(void)>>(
            // 这点之所以需要绑定是因为我们能在packaged_task里指定 了函数的参数为void
            bind(forward<F>(f), forward<Args>(args)...)
        );

        // 拿到packaged_task的future，等待工作线程返回时这个线程的返回值就放在了future中
        future<returnType> res = task->get_future();
        {
            lock_guard<mutex> lock(m_taskMutex);
            // 这点会使task的引用计数+1，这点不能用引用捕获，因为超出这个返回智能指针会自动释放packaged_task的对象
            m_tasks.emplace([task]() {
                (*task)();
            });
        }
        // cout << "task.count(): " << task.use_count() << endl; task.use_count() = 2
        m_condition.notify_one();
        return res;
    }

private:

    // 管理者线程
    void manager(); 
    // 工作线程    
    void worker();      

private:
    thread *m_manager;
    map<thread::id, thread> m_workers;
    vector<thread::id> m_ids;
    int m_minThreads;
    int m_maxThreads;
    atomic<bool> m_stop;
    atomic<int> m_curThreads;
    atomic<int> m_idleThreads;
    atomic<int> m_exitNumber;
    queue<function<void()>> m_tasks;
    mutex m_idsMutex;
    mutex m_taskMutex;
    condition_variable m_condition;
};

#endif