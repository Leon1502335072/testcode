#include <iostream>
#include <thread>
#include <string>
#include <functional>
using namespace std;

void fun1()
{
    cout << "child-1 thread Id = " << this_thread::get_id() << endl;
}

void fun2(int a, string str)
{
    cout << "child-2 thread Id = " << this_thread::get_id() << endl;
}

// 测试线程加载普通函数
void ordinaryFunction()
{
    cout << "main thread Id = " << this_thread::get_id() << endl;
    thread t1;

    thread t2(fun1);

    thread t3(fun2, 1, "hello");

    thread t4([=](int a)
              { cout << a << " - child-3 thread Id = " << this_thread::get_id() << endl; }, 123);

    thread&& t5 = move(t4);


    t2.join();
    t3.join();
    t5.join();
}

class Base
{
public:
    Base() {}
    ~Base() {}
    void fun(int a)
    {
        cout << a << " - child thread Id = " << this_thread::get_id() << endl;
    }
    static void fun1() 
    {
        cout << "child thread Id = " << this_thread::get_id() << endl;
    }
};

// 类的成员函数
void classMemberFunction()
{
    // 类的静态成员函数
    thread t1(&Base::fun1);

    // 类的普通函数
    Base b1;
    thread t2(&Base::fun, &b1, 1);

    thread t3(bind(&Base::fun, &b1, 123));
    t1.join();
    t2.join();
    t3.join();
}

int main(int arg, char** argv)
{
    //ordinaryFunction();
    classMemberFunction();
    return 0;
}