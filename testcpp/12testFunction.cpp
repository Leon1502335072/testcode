#include <iostream>
#include <functional>
#include <vector>
#include <memory>
using namespace std;

void fun1(function<void()> cb)
{
    cb();
}

void fun2(function<int()> cb)
{
    cb();
}

int p(int a, int b)
{
    cout << "p(a, b)" << endl;
    cout << "a= " << a << " " << "b= " << b << endl;
    return 0;
}
void q(int a, int b)
{
    cout << "p(a, b)" << endl;
    cout << "a= " << a << " " << "b= " << b << endl;
}

struct info
{
    int a = 0;
};


int main()
{
    fun1(bind(p, 1, 2));
    fun2(bind(p, 10, 20));

    
    // weak_ptr<info> w1(new info);
    shared_ptr<info> s1(new info);
    weak_ptr<info> w1(s1);

    // vector<int> vec(5);
    // for (int i = 0; i < vec.size(); ++i)
    // {
    //     vec[i] = i;
    // }

    // vec.resize(10);
    // for (int i = 0; i < vec.size(); ++i)
    // {
    //     cout << vec[i] << endl;
    // }
    return 0;
}