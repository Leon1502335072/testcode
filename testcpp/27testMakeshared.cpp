#include <iostream>
#include <memory>
using namespace std;

class Base
{
public:
    typedef shared_ptr<Base> ptr;
    void fun()
    {
        cout << "Base::fun" << endl;
    }
    ~Base() { cout << "~Base()" << endl; }
};

int main()
{
    {
        auto Bptr = std::make_shared<Base>();
        Bptr->fun();
    }
    
    return 0;
}