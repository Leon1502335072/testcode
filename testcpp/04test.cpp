#include <iostream>
#include <memory>
#include <string>
using namespace std;

class base
{
public:
    typedef shared_ptr<base> ptr;
    base() {}
    ~base() {}
    virtual void fun()
    {
        cout << "base!!!" << endl;
    }
};
class derive: public base
{
public:
    typedef shared_ptr<derive> ptr;
    derive() {}
    ~derive() {}
    
    void fun()
    {
        cout << "derive!!!" << endl;
    }
    
    void fun1()
    {
        cout << "fun1 derive!!!" << endl;
    }

};
class temp : public base
{
public:
    typedef shared_ptr<temp> ptr;
    temp() {}
    ~temp() {}

    void fun()
    {
        cout << "temp!!!" << endl;
    }
    void func2()
    {
        return;
    }
};

template <class T>
static uint32_t CountBytes(T value)
{
    uint32_t result = 0;
    for (; value; ++result)
    {
        value &= value - 1;
    }
    return result;
}

int main()
{
    //uint32_t value = 7;
    //cout << "uint32_t type " << value << " have 1 counts: " << CountBytes<uint32_t>(value) << endl;

    // base::ptr pbase(new derive);
    // pbase->fun();
    // temp::ptr t = dynamic_pointer_cast<temp>(pbase);
    // if (t)
    // {
    //     cout << "cun zai" << endl;
    // }
    // cout << "(uint64_t)-1 = " <<(uint64_t)-1 << endl;

    // cout << "-------------------------------" << endl;

    string buff;
    buff.resize(10);
    const char* chr = "hello";
    const char chr1[] = "world";
    cout << "&buff: " << &buff << "  " << "&buff[0]: " << &buff[0] << endl;
    cout << "chr: " << &chr << "  " << "&chr[0]: " << &chr[0] << endl;

    cout << "&chr1: " << &chr1 << "  " << "&chr1[0]: " << &chr1[0] <<"  "<< "chr1: " << chr1 << endl;

	return 0;
}