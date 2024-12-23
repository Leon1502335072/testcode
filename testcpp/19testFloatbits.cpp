#include <iostream>
#include <stdio.h>
#include <string>
#include <memory>
using namespace std;


class Base : public enable_shared_from_this<Base>
{
public:
    typedef shared_ptr<Base> ptr;
    Base() {}
    ~Base() {}
    template<class T>
    void func(T m)
    {
        cout << m << endl;
    }
    // void func1(int a)
    // {
    //     func(a);
    // }
    // virtual void funx() {}  

};

int main() 
{
    Base b;
    string str;
    str.resize(10);
    if(str.empty())
        cout << "str empty" << endl;
    else
        cout << "str not empty" << endl;
    printf("Size of float: %lu bytes\n", sizeof(float));



    cout << "sizeof(Base): " << sizeof(Base) << endl;
    return 0;
}