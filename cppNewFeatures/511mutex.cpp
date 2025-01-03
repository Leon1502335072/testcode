#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;
using namespace chrono;

#if 0
class Calculate
{
public:
    int mul(int x)
    {
        m_i *= x;
        return m_i;
    }

    int div(int x)
    {
        m_i /= x;
        return m_i;
    }

    void both(int x, int y)
    {
    }

private:
    int m_i;
};
#endif
// 互斥锁
class Base
{
public:
    void increment(int count)
    {
        for (int i = 0; i < count; ++i)
        {
            mx.lock();
            ++number;
            cout << "++current number: " << number << endl;
            mx.unlock();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

    void decrement(int count)
    {
        for (int i = 0; i < count; ++i)
        {
            //mx.lock();
            {
                lock_guard<mutex> guard(mx);
                increment(2);
                --number;
                cout << "--current number: " << number << endl;
            }
            //mx.unlock();
            this_thread::yield();
        }
    }

    void work()
    {
        while (true)
        {
            // 尝试获取锁并给这把锁夹一个超时时间100毫秒 成功返回true
            if (tmx.try_lock_for(chrono::milliseconds(100)))
            {
                count++;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "ok = 抢到了互斥锁所有权, 线程ID: " << this_thread::get_id() << endl;
                tmx.unlock();
                break;
            }
            else
            {
                cout << "notok = 没有抢到互斥锁所有权, 线程ID: " << this_thread::get_id() << endl;
                this_thread::sleep_for(chrono::milliseconds(50));
            }
        }
    }
private:
    int number = 999;
    int count = 0;
    mutex mx;           // 独占互斥量
    timed_mutex tmx;    // 带超时时间的互斥量
};

int main()
{
    Base b;
    thread t1(&Base::work, &b);
    thread t2(&Base::work, &b);
    t1.join();
    t2.join();

    return 0;
}
