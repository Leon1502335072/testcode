#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Base
{
public:
    Base() 
    {
        name = "leon";
        age = 20;
        sex = 1;
        vec = {1, 2, 3};
    }
    ~Base() {}
    template<class T>
    void func(T m)
    {
        cout << m << endl;
    }

    void func1(int a)
    {
        func(a);
    }

    friend ostream &operator<<(ostream &os, const Base &b);

private:
    string name;
    int age;
    int sex;
    vector<int> vec;
};

ostream& operator<<(ostream& os, const Base& b)
{
    os << "name: " << b.name << "\n"
        << "age: " << b.age << "\n"
        << "sex: ";
    if(b.sex==1)
    {
        os << "male" << "\n";
    }
    else
    {
        os << "female" << "\n";
    }
    os << "vec: "<<"[ ";
    for (int i = 0; i < b.vec.size(); ++i)
    {
        os << b.vec[i];
        if(i == b.vec.size()-1)
        {
            os << " ]";
            break;
        }
        os << ", ";
    }
    return os;
}



int main()
{
    Base b;
    // b.func("string");
    // b.func1(13);
    cout << b << endl;

    return 0;
}