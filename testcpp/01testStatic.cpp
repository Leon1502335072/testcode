#include <iostream>
#include <string>
#include <map>
using namespace std;

int m_a;
int& fun1()
{
    m_a = 10;
    return m_a;
}

// 不安全，不能返回局部变量的引用类型
int& fun()
{
    //static int a = 10; 静态局部变量可返回引用，但外部修改时不会引起该局部静态变量的变化
    int a = 10;
    return a;
}

class Base
{  
public:
    void fun()
    {
        cout << b << endl;
        fun1();
    } 
    // 静态成员函数不能访问非静态成员
    static int& fun1()
    {
        static int count = 1;
        count++;
        cout << "count: " << count << endl;
        return count;
    }
    
    static map<int, string>& Getdata()
    {
        static map<int, string> myMap;
        return myMap;
    }
    
    // 静态成员函数可以改变局部静态数据的值
    static void lookup(const int& a, const string& str)
    {
        auto it = Getdata().find(a);
        if(it==Getdata().end())
        {
            Getdata()[a] = str;
        }
        cout << "Getdata().size(): " <<Getdata().size() << endl;
    }

public:
    int a = 10;
    static int b;

};

int Base::b = 20;

int main()
{
    Base c, d;
    //c.fun();

    c.fun1();
    d.fun1();

    Base::lookup(1, "hello");
    Base::lookup(2, "world");
    // int &b = fun1();
    //  int b = fun();
    // cout << b << endl;
    //  cout << "hello world" << endl;
    //  for (int i = 1; i < 10; ++i)
    //  {
    //      for (int j = 1; j <= i; ++j)
    //      {
    //          cout << j << " × " << i << " = " << i * j <<"  ";
    //      }
    //      cout << endl;
    //  }

    return 0;
}