#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int myfunc(int a, string s) {}


// 1、函数返回值类型后置
template<class T, class F>
auto fun(const T& t, const F& f) -> decltype(t + f)
{
    return t + f;
}


// 2、final关键字：修饰类表示这个类不能被继承了，修饰函数一般是修饰子类重写父类的虚函数表示再往下继承就不要再重写了（注意：父类中的虚函数一般不能加这个关键字）
class Base
{
public:
    virtual void fun() {}
};
class Derive : public Base
{
public:
    void fun() final { cout << "hello" << endl; }
};

// 3、using 的另一个用处就是用来定义别名和 typedef 差不多
typedef int myint1;
using myint = int;

typedef int (*pf1)(int, string);
using pf = int(*)(int, string);

// template <class T> 使用typedef
// struct MM
// {
//     typedef map<int, T> myMap;
// };

template <class T>
using myMap = map<int, T>;

// 4、委托构造（调用构造）  继承构造

// 5、std::initializer_list<> 接收任意多个相同类型的参数
void fun5(std::initializer_list<int> ls)
{
    auto it = ls.begin();
    for (; it != ls.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int arg, char* argv[])
{
    auto ret = fun(2, 3.14);
    cout << "ret = " << ret << endl;
    // 4
    myMap<int> mmp;
    mmp.insert(make_pair(1, 1));

    // 5
    fun5({1, 2, 3, 4, 5, 6});

    return 0;
}