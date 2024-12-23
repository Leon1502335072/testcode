#include <iostream>
using namespace std;

struct HTTP_PARSER
{
    // a变量占32位中的3位
    unsigned int a : 3;
    int b;
};

int main()
{
    HTTP_PARSER pa;
    // 12 -> 1100 去后三位 110 所以输出pa.a是4
    pa.a = 12;
    cout << pa.a << endl;
    cout << pa.b << endl;
    return 0;
}