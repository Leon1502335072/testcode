#include <iostream>
#include <thread>
#include <string>
#include <functional>
#include <mutex>
using namespace std;

once_flag flag;

class Base
{
public:
    Base(const Base &others) = delete;
    Base &operator=(const Base &others) = delete;

    static Base* getInstance()
    {
        call_once(flag, [&]()
                { 
                    base = new Base; 
                    cout<<"实例对象被创建..."<<endl; 
                });
        return base;
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }

private:
    Base() {}
    static Base *base;
    string name;
};
Base *Base::base = nullptr;

void myfunc(string name)
{
    Base::getInstance()->setName(name);
    cout <<"my name is: " <<Base::getInstance()->getName() << endl;
}

int main(int arg, char** argv)
{
    thread t1(myfunc, "luffy");
    thread t2(myfunc, "leon");
    thread t3(myfunc, "jerry");
    thread t4(myfunc, "erich");

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}