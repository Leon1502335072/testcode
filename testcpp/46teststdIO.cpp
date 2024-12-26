#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void testStdio()
{
    string s;
    cout << "请输入一个字符串：" << endl;
    getline(cin, s);
    stringstream ss(s);

    // string s1;
    // ss >> s1;
    // cout << ss.str() << s1 << endl;

    cout<<"处理后的字符串为:"<<endl;    //将string流里的东西输出
    for(string str; ss >> str; cout << str << endl);

}

void testFileIO()
{
    // readfile("../README.md");也可以直接将文件路径传入构造函数
    ifstream readfile;
    readfile.open("../README.md");
    if(!readfile)
    {
        cout << "can not open the input file" << endl;
        return;
    }
    string s;
    int i = 0;
    while (getline(readfile, s))
    {
        ++i;
        cout << s << endl;
    }
    cout << i << endl;
    readfile.close();

    ofstream of;
    of.open("test.txt", std::ios_base::app); //追加写
    for (int i = 0; i < 3; ++i)
    {
        of << "thread-" + to_string(i) << endl;
    }
    of.close();
}

int main(int arg, char* argv[])
{
    testFileIO();

    return 0;
}