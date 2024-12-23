#include <iostream>
#include <memory>
#include <string>
#include <stdio.h>
using namespace std;

template<class T, class F = void, int N = 0>
class Singleton
{
public:
    static T* Getinstance()
    {
        static T v;
        return &v;
    }
};

template<class T, class F = void, int N = 0>
class SingletonPtr
{
public:
    static shared_ptr<T> Getinstance()
    {
        static shared_ptr<T> v(new T);
        return v;
    }
};

class Base
{
public:
    typedef shared_ptr<Base> ptr;
    void fun()
    {
        std::cout << "Base::fun" << std::endl;
    }   
};


class person
{
public:
    typedef shared_ptr<person> ptr;
    void fun()
    {
        std::cout << "person::fun" << std::endl;
    }
    static person* getinstance()
    {
        static person p;
        return &p;
    }
    ~person() { cout << "~person" << endl; }

private:
    person() {cout << "person" << endl;}
};

typedef Singleton<Base> BSingleton;
typedef SingletonPtr<Base> BSingletonPtr;
int main()
{
    // person::getinstance()->fun();
    // Base b;
    // Base *b1 = new Base;
    // cout << "&b: " << &b << endl;
    // cout << "b1: " << b1 << endl;
    // cout << "&b1: " << &b1 << endl;
    BSingleton::Getinstance()->fun();
    cout << "BSingleton::Getinstance(): " << BSingleton::Getinstance() << endl;
    cout << "BSingleton::Getinstance(): " << BSingleton::Getinstance() << endl;

    BSingletonPtr::Getinstance()->fun();
    cout << "BSingletonPtr::Getinstance(): " << BSingletonPtr::Getinstance() << endl;
    cout << "BSingletonPtr::Getinstance(): " << BSingletonPtr::Getinstance() << endl;
    // cout << "-------------------------------" << endl;
    // const char *str = "hello";
    // string str1(str);

    // printf("str: %p\n", str);
    // printf("&str: %p\n", &str);
    // printf("&str[0]: %p\n", &str[0]);
   

    // cout << "&str1: " << &str1 << endl;
    // cout << "&str1[0]: " << &str1[0] << endl;

    return 0;
}