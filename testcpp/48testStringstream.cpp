#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void test1()
{

    // 创建一个字符串流对象
    std::stringstream ss;
 
    // 写入数据到字符串流
    int num = 42;
    double pi = 3.14159;
    ss << "Number: " << num << ", Pi: " << pi;

    // 获取字符串流的内容
    std::string str = ss.str();
    std::cout << "Stream content: " << str << std::endl;

    string temp;
    ss >> temp;
    cout << temp << endl;
    // 清空字符串流
    ss.str("");
    ss.clear();
    int a = 100;
    int b = 200;
    ss << a << b;
    uint8_t c;
    ss >> c;
    cout << ss.str() << endl;
    cout << c << endl;

    ss.str("");
    ss.clear();
    cout << "after clear: "<<ss.str() << endl;
}

int main(int arg, char* argv[])
{
    test1();
    return 0;
}