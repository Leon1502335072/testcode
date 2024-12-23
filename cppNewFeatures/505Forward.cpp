#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

template<class T>
void printVlaue(T& t)
{
    cout << "左值：" << t << endl;
}

template<class T>
void printVlaue(T&& t)
{
    cout << "右值：" << t << endl;
}

template<class T>
void testForward(T&& v)
{
    printVlaue(v);
    printVlaue(move(v));
    printVlaue(forward<T>(v));
    cout << endl;
}

int main(int arg, char* argv[])
{
    testForward(520);
    int num = 1314;
    testForward(num);
    // 只要forward<T> 的T不是左值引用类型那么经过forward转发后的都是右值
    testForward(forward<int>(num));
    testForward(forward<int&>(num));
    testForward(forward<int&&>(num));

    std::shared_ptr<int> ptrint = std::make_shared<int>(10);
    cout << *ptrint << endl;

    return 0;
}