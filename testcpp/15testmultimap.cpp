#include <iostream>
#include <string.h>
#include <string>
#include <map>
using namespace std;

class Base
{
public:
    Base() {}
    virtual ~Base() {}
    void fun()
    {
        Func();
    }
    virtual void Func() = 0;
};

int main()
{
    multimap<string, string> map_datas;
    map_datas.insert(make_pair("a", "12"));
    map_datas.insert(make_pair("a", "123"));
    map_datas.insert(make_pair("a", "1234"));
    map_datas.insert(make_pair("a", "12345"));
    map_datas.insert(make_pair("a", "123456"));

    auto its = map_datas.equal_range("a");
    for (; its.first != its.second; ++its.first)
    {
        // its.first->first 这个是 key
        // its.first->second 这个是 value
        cout << " its.first->first: " << its.first->first 
        << " its.first->second: " << its.first->second << endl;
    }

    return 0;
}