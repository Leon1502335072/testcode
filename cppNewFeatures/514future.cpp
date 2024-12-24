#include <iostream>
#include <atomic>
#include <string>
#include <future>
#include <thread>
#include <chrono>
#include <functional>
using namespace std;
using namespace chrono;

void fun(promise<string>& p)
{
    // 睡眠500毫秒
    this_thread::sleep_for(chrono::milliseconds(500));
    p.set_value("你好我是路飞，我要成为海贼王！！！");
    this_thread::sleep_for(chrono::milliseconds(100));
}

string myFunc()
{
    this_thread::sleep_for(chrono::seconds(3));
    return "我是路飞，要成为海贼王。。。";
}

using funcPtr = string(*)(string, int);
class Base
{
public:
    // 重载()
    string operator()(string msg)
    {
        string str = "operator() function msg: " + msg;
        return str;
    }

    // 将对象变为函数指针
    operator funcPtr()
    {
        return showMsg;
    }

    int getNumber(int num)
    {
        int number = num + 100;
        return number;
    }

    static string showMsg(string msg, int num)
    {
        string str = "showMsg() function msg: " + msg + ", " + to_string(num);
        return str;
    }
};


int main(int arg, char *argv[])
{
    cout << "主线程Id = " << this_thread::get_id() << endl;

    // 这种不会创建新的线程
    future<string> f = async(launch::deferred, [](int num)
                                                {
                                                cout << "子线程Id = " << this_thread::get_id() << endl;
                                                return string("我是海贼王...") + to_string(num); }, 200);
    
    // // 这种也会创建下的线程
    // future<string> f = async(launch::async, [](int num)
    //                                         {
    //                                         cout << "子线程Id = " << this_thread::get_id() << endl;
    //                                         return string("我是海贼王...") + to_string(num); }, 200);
    
    this_thread::sleep_for(chrono::seconds(3));
    // // 这种会创建新的线程来执行任务
    // future<string> f = async([](int num)
    //                          {
    //                         cout << "子线程Id = " << this_thread::get_id() << endl;
    //                         this_thread::sleep_for(chrono::seconds(3));
    //                         return string("我是海贼王...") + to_string(num); }, 200);
    future_status status;
    do
    {
        status = f.wait_for(chrono::seconds(1));
        if(status == future_status::deferred)
        {
            cout << "子线程还没有执行..." << endl;
            f.wait();
        }
        else if(status == future_status::ready)
        {
            cout << "数据就绪了, 子线程返回的数据是: " << f.get() << endl;
        }
        else if(status == future_status::timeout)
        {
            cout << "子线程还在执行, 超时时长用完了, 继续等待..." << endl;
        }

    } while (status != future_status::ready);

#if 0
    // 对普通函数函数打包packaged_task<函数返回值类型(参数列表)>
    packaged_task<string(void)> task1(myFunc);

    // 对匿名函数打包
    packaged_task<int(int)> task2([](int arg) {
        return 100;
        });
    
    // 对仿函数打包
    Base ba;
    packaged_task<string(string)> task3(ba);

    // 将类对象进行转换得到的函数指针 然后再打包
    Base bb;
    packaged_task<string(string, int)> task4(bb);

    // 对类的静态成员函数打包
    packaged_task<string(string, int)> task5(&Base::showMsg);
   
    // 对类的普通非静态函数
    Base bc;
    auto obj = bind(&Base::getNumber, &bc, placeholders::_1);
    packaged_task<int(int)> task6(obj);

    // 将打包好的对像的引用传给子线程对象
    thread t1(ref(task6), 200);
    future<int> f = task6.get_future();
    int num = f.get();
    cout << "子线程返回值: " << num << endl;
    t1.join();
#endif




#if 0
    promise<string> pro;
    //thread t1(fun, ref(pro));

    thread t1([](promise<string> &p)
              {
                  this_thread::sleep_for(chrono::seconds(1));
                  p.set_value("却道天凉好个秋！");
                  this_thread::sleep_for(chrono::seconds(2)); 
              }, ref(pro));

    // 在主线程中拿到子线程中的数据
    future<string> f = pro.get_future();
    cout << f.get() << endl;

    t1.join();
#endif


    return 0;
}