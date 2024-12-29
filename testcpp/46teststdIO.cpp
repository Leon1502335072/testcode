#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct people
{
    char name[20];
    int age;
    int weight;
}p;
const char *file = "fileName.txt";

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

// 二进制读取和写入
void testIOBinary()
{
    fstream f;
    f.open(file, std::ios_base::binary | std::ios_base::in | std::ios_base::out);
    if(f.is_open())
    {
        while(f.read((char*)&p, sizeof(p)))
        {
            cout << "name: " << p.name << endl;
            cout << "age: " << p.age << endl;
            cout << "weight: " << p.weight << endl;
        }
        // 重置流状态
        f.clear();
    }
    else
    {
        // 如果文件未存在

        // 重置文件流转台
        f.clear();
        // //以写入文件的方式打开文件，即创建该文件
        f.open(file, std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
    }

    // 设置输出文件指针位置
    f.seekp(0, ios_base::end);
    cout << "请输入名字: ";
    cin.get(p.name, 20);

    while(p.name[0]!='\0')
    {
        while(getchar()!='\n');
        cout << "请输入年龄: ";
        cin >> p.age;
        while(getchar()!='\n');
        cout << "请输入重量(kg): ";
        cin >> p.weight;
        while(getchar()!='\n');

        // 写入文件
        f.write((char *)&p, sizeof(p));
        
        cout << "请输入名字: ";
        cin.get(p.name, 20);
    }

    f.close();
    f.clear();

    // 重新打开文件
    f.open(file, std::ios_base::binary | std::ios_base::in);
    if(f.is_open())
    {
        while(f.read((char*)&p, sizeof(p)))
        {
            cout << "name: " << p.name << endl;
            cout << "age: " << p.age << endl;
            cout << "weight: " << p.weight << endl;
        }
    }
    else
    {
        cout << "文件打开失败..." << endl;
        
    }
    f.close();
    f.clear();
}



int main(int arg, char* argv[])
{
    //testFileIO();
    testIOBinary();

    return 0;
}