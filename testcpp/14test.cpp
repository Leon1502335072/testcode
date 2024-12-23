#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Base
{
public:
    Base() {}
    virtual ~Base() {}
    void fun()
    {
        Func();
    }
    virtual void Func() = 0;
};

class Derive : public Base
{
public:
    Derive() {}
    ~Derive() {}

    virtual void Func()
    {
        cout << "Derive::Func" << endl;
    }
};


int main()
{
    Base* b = new Derive;
    //b->fun();
    string host = "192.168.200.130:8080";
    const char *service = NULL;
    service = (const char* )memchr(host.c_str(), ':', host.size());

    cout << "host.c_str() + host.size() - service - 1: " << (host.c_str() + host.size() - service - 1) << endl;
    //memchr(service + 1, ':', host.c_str() + host.size() - service - 1);

    
    cout << *service << endl;

    return 0;
}