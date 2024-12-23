#include <iostream>
#include <strings.h>
#include <map>
#include <string>
#include <boost/lexical_cast.hpp>
using namespace std;

template<class T, class F>
class LexicalCast
{
public:
    T operator ()(const F& val)
    {
        return boost::lexical_cast<T>(val);
    }
};

template<class T, class F>
class LexicalCast
{
public:
    T operator ()(const F& val)
    {
        return boost::lexical_cast<T>(val);
    }
};

struct CaseInsensitiveLess 
{
    bool operator()(const std::string& lhs, const std::string& rhs) const
    {
        return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

map<string, string, CaseInsensitiveLess> myMap;



int main()
{
    // myMap["key"] = "hello";
    // myMap["Key"] = "world";
    // myMap["Hey"] = "oppo";
    // myMap["Pom"] = "huawei";

    // for(auto& [x, y]:myMap)
    // {
    //     cout << x << "  " << y << endl;
    // }

    string str = LexicalCast<string, int>()(123);
    cout << str << endl;

    return 0;
}