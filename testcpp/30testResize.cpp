#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

struct Nio 
{
    typedef shared_ptr<Nio> ptr;
    int m_a;
    string name;
};

int main()
{
    vector<Nio::ptr> vec;
    vec.resize(10);
    if(vec[1])
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}