#include <iostream>
#include <string>
using namespace std;

// 在后面代码中遇到HTTP_METHOD_MAP(XX)就替换成后面一大坨东西

#define HTTP_METHOD_MAP(XX)     \
    XX(0,  GET,          GET)   \
    XX(1,  DELETE,    DELETE)   \
    XX(2,  HEAD,        HEAD)   \
    XX(3,  POST,        POST)   \
    XX(4,  PUT,          PUT)

enum http_method
{
#define xx(number, name, discription) http_##name = number,
    HTTP_METHOD_MAP(xx)
#undef xx
};

enum class METHOD
{
#define xx(num, name, description) name = num,
    HTTP_METHOD_MAP(xx)
#undef xx
};



#ifndef HTTP_PARSER_STRICT
#define HTTP_PARSER_STRICT 1
#endif
 
#define ToString(a) #a

// 
static const char *HTTP_METHOD_ARRAY[] =
{
#define xx(num, name, string) #string,
        HTTP_METHOD_MAP(xx)
#undef xx
};

const char* httpMethodToString(const METHOD& m)
{
    uint32_t idx = (uint32_t)m;
    // 数组中放的是指针，linux下一个指针大小是8个字节 所以该数组的大小是40 即 40/8 =5 为数组的size
    if(idx > (sizeof(HTTP_METHOD_ARRAY) / sizeof(HTTP_METHOD_ARRAY[0])))
    {
        return "<unknow>";
    }
    return HTTP_METHOD_ARRAY[idx];
}

const char* httpMethodToString2(const METHOD& m)
{
    switch (m)
    {
    #define xx(num, name, string) \
        case METHOD::name:        \
            return #string;
            HTTP_METHOD_MAP(xx)
    #undef xx
    default:
        return "<unknow>";
    }
}

int main()
{
    int a = 0;
    http_method::http_DELETE;
    METHOD::DELETE;
    
    cout << httpMethodToString(METHOD::DELETE) << endl;
    cout << httpMethodToString2(METHOD::DELETE) << endl;
    cout << httpMethodToString2((METHOD)http_method::http_POST) << endl;

    cout << "HTTP_PARSER_STRICT: " << HTTP_PARSER_STRICT << endl;
    if(ToString(1)=="1")
    {
        cout << "ToString(1)==\"1\"" << endl;
    }

    string sq;
    string ss("123456");
    string sp("123456123");
    cout << "sizeof(sq): " << sizeof(sq) << endl;
    cout << "sizeof(ss): " << sizeof(ss) << endl;
    cout << "sizeof(sp): " << sizeof(sp) << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;
    return 0;
}