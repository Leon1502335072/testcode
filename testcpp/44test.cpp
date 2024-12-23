#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

// 可变参数模版

#if 0
void fun(int& m, string&& str, int&& pp)
{
    cout << m << " " << str << endl;
}

template<class T, class...Args>
void do_io(int&& a, const T& t, Args&&... args)
{
    fun(a, std::forward<Args>(args)...);
}

template<class... T>
void myPrint(T... args)
{
    cout << "接收的参数个数：" << sizeof...(args) << endl;
    cout << "接收到的参数类型个数：" << sizeof...(T) << endl;
}
#endif

#if 0
// 可变参数的递归展开
void myvtfunct() // 这是一个普通函数，不是函数模板
{
    std::cout << "参数包展开时执行了递归终止函数myvtfunct()" << std::endl;
}

template<class T, class... U>
void myvtfunct(T firstarg, U... otherargs)
{
    cout << "接收到的参数值为：" << firstarg << endl;
    // 递归打印每一个参数，最后为为空时调用上面的重载myvtfunct()
    myvtfunct(otherargs...);
}
#endif

#if 0
// 通过constexpr if优化递归
template<class T, class... U>
void myvtfunct(T firstarg, U... otherargs)
{
    cout << "接收到的参数值为：" << firstarg << endl;
    if constexpr (sizeof...(otherargs) > 0)
    {
        myvtfunct(otherargs...);
    }
}
#endif

#if 0
// 可变参数函数模版的重载
void myvtfunct(int arg)
{
    cout << "myvtfunct() 被调用" << endl;
}

template<class... T>
void myvtfunct(T... args)
{
    cout << "myvtfunct(T... ) 被调用" << endl;
}

template<class... T>
void myvtfunct(T*... args)
{
    cout << "myvtfunct(T*...) 被调用" << endl;
}
#endif


#if 0
// 折叠表达式
// 一元左折
template<class... T>
int add_val(T... args)
{
    return (... + args);
}

template<class... T>
auto sub_val_left(T... args)
{
    return (... - args); // 左折叠，从左向右进行减法
}

template<class... T>
auto sub_val_right(T... args)
{
    return (args - ...); // 右折叠，从右向左进行减法
}

// 二元左折
template <class... T>
auto add_val_left_2(T... args)
{
    // add_val_left_2(10,20,30) => ((220+10)+20)+30 = 280
    return (220 + ... + args);
}

// 二元右折
template <class... T>
auto sub_val_right_2(T... args)
{
    // sub_val_right_2(10,20,30) => 10-(20-(30-220)) = -200
    return (args - ... - 220);
}
#endif


#if 0
template<class... T>
auto print_result(T... args)
{
    (cout << ... << args) << " 结束" << endl;
    return (... + args);
}

template <class... T>
auto print_calc(T... args)
{
    // 其实第一种加括号的更好理解
    cout << print_result((2 * args)...) << endl;
    cout << print_result(2 * args...) << endl;
    cout << print_result(args * 2 ...) << endl;
    cout << print_result(args + args ...) << endl;
}
#endif

#if 0
// 通过递归继承展开类型参数包，每个实例化处理一个类型的值，继承链中的每一层都负责一个类型。
// 基本模板定义，不包含任何成员。
template <class... args>
class myclass {};

// 递归模板特化，用于处理至少一个类型参数。
template <class First, class... Others>
class myclass <First, Others...>:public myclass<Others ...>
{
private:
    First val;
public:
    // 构造函数，初始化当前类型的值并递归初始化基类。
    myclass(First f, Others... others ): myclass<Others...>(others...),val(f) {}
    // 打印函数，打印当前值并调用基类的print方法。
    void print()
    {
        cout << val << endl;
        myclass<Others...>::print();
    }
};

// 模板特化，用作递归终止条件。
template <>
class myclass<>
{
public:
    void print() {} // 空打印函数
};
#endif

#if 0
// 通过元组和递归调用展开参数包
// 定义一个模板类 TupleWrapper，内部使用 std::tuple 来存储参数包
template <class... Args>
class TupleWrapper
{
private:
    // data 成员变量是一个元组，存储传入的所有参数
    tuple<Args...> data;
public:
    // 构造函数，使用 std::make_tuple 将所有参数打包成一个元组
    TupleWrapper(Args... args) : data(make_tuple(args...)) {}

    // get 成员函数模板，用于获取元组中指定位置的值
    template<size_t N>
    decltype(auto) get() const
    {
        // 使用 std::get 来访问元组中的特定元素
        return std::get<N>(data);
    }
};
#endif

// 基类参数包的展开
template <class... BaseClasses>
class myclass : public BaseClasses...
{
public:
    myclass():BaseClasses()...
    {
        cout << "myclass::myclass this = " << this << endl;
    }
private:
    char ch[50];
};

class PA1
{
public:
    PA1()
    {
        cout << "PA1::PA1 this = " << this << endl;
    }
private:
    char ch[100];
};

class PA2
{
public:
    PA2()
    {
        cout << "PA2::PA2 this = " << this << endl;
    }
private:
    char ch[200];
};

class PA3
{
public:
    PA3()
    {
        cout << "PA3::PA3 this = " << this << endl;
    }
private:
    char ch[300];
};

int main(int arg, char *argc[])
{
    //do_io(10, 0, "hello world", 100);
    // myPrint();
    // myPrint(10, 20);
    // myPrint(10, 20, "hello");
    // myPrint<double, double>(1, 1.02, "world", 11, 1.2);

    // myvtfunct(0);
    // myvtfunct(NULL);
    // myvtfunct(nullptr);
    // myvtfunct((void *)nullptr);

    // cout << add_val(10, 20, 30, 40) << endl;       // ((10+20)+30)+40 = 100
    // cout << sub_val_left(10, 20, 30, 40) << endl;  // ((10-20)-30)-40 = -80
    // cout << sub_val_right(10, 20, 30, 40) << endl; // 10-(20-(30-40)) = -20
    // cout << add_val_left_2(10, 20, 30) << endl;
    // cout << sub_val_right_2(10, 20, 30) << endl;

    // print_calc(1, 2, 3);

    // myclass<int, string, double> obj(1, "hello", 3.102);
    // obj.print();

    // TupleWrapper<int, double, char> wrapper(10, 3.012, 'A');
    // cout << "int: " << wrapper.get<0>() << endl;
    // cout << "double: " << wrapper.get<1>() << endl;
    // cout << "char: " << wrapper.get<2>() << endl;

    myclass<PA1, PA2, PA3> obj;
    std::cout << "sizeof(obj) = " << sizeof(obj) << std::endl; // 输出对象大小，应为600

    string str("123456789");
    string str1("hello");
    cout << "sizeof(str) = " << sizeof(str) << endl;
    cout << "sizeof(str1) = " << sizeof(str1) << endl;
    vector<int> vec(1, 1);
    cout << "sizeof(vec) = " << sizeof(vec) << endl;
    return 0;
}