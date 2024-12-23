#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Test
{
public:
    Test() { cout << "construct function!!!" << endl; }
    ~Test() { cout << "destroy function..." << endl; }
private:
    int a = 10;
};

int main(int arg, char* argv[])
{

    std::shared_ptr<int> ptrint = std::make_shared<int>(10);
    cout << *ptrint << endl;

    // 如果管理的是一个数组类型 需要自定义删除器或者使用默认的删除器
    std::shared_ptr<Test> pp(new Test[5], [](Test *t){ delete[] t; });
    // 使用系统自带的默认删除器
    std::shared_ptr<Test> ppp(new Test[5], default_delete<Test[]>());

    return 0;
}