#include <iostream>
using namespace std;

class Base1
{
public:
    virtual void Base1fun() { cout << "Base1fun" << endl; }
};

class Base2
{
public:
    virtual void Base2fun() { cout << "Base2fun" << endl; }
};

class Dervie : public Base1, public Base2
{
public:
    virtual void Base1fun() override { cout << "Dervie::Base1fun" << endl; }
    virtual void Base2fun() override { cout << "Dervie::Base2fun" << endl; }
};

// 测试using Base3::Base3; 子类Dervie1继承了父类Base3所有的构造函数
// class Base3
// {
// public:
//     Base3() = default;
//     Base3(int a) {}
//     Base3(int a, int b) {}
// };

// class Dervie1 : public Base3
// {
// public:
//     using Base3::Base3;
// };

int main(void)
{
    Base1* b1 = new Base1;
    Base2* b2 = new Base2;
    Base1* p1 = new Dervie;
    Base2* p2 = new Dervie;

    p1->Base1fun();
    p2->Base2fun();

    delete p1, p2;
    delete b1, b2;

    // Dervie1 d(1);
    // Dervie1 d2(1, 2);
    return 0;
}