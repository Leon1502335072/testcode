#include <sstream>
#include <string>
#include <iostream>
using namespace std;

void fun(ostream& os)
{
    os << "hello fun~" << endl;
}

int main() 
{
    std::string input = "Hello, World! This is a test message with an integer:  42";
    std::istringstream iss(input);
    std::string greeting;
    std::string message;
    std::string test;
    int number;
    // 从字符串流中提取数据 默认是以空格作为分隔符提取子串的
    iss >> greeting >> message >> test;
    std::getline(iss, message, ':'); // 使用 ':' 作为分隔符提取子串
    iss >> number;
    // 输出提取的数据
    std::cout << "Greeting: " << greeting << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "Integer: " << number << std::endl;

    //ostream os;
    stringstream ll;
    fun(ll);
    cout << ll.str();

    return 0;
}
