#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Base
{
public:
    Base(const string &_name, const int& _age, const int& _sex, vector<int>&& _vec) 
    {
        name = _name;
        age = _age;
        sex = _sex;
        vec = _vec;
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
    Base b("jack", 22, 1, vector<int>{100, 92, 89});
    Base p("shelly", 20, 0, vector<int>{93, 94, 95});
    // b.func("string");
    // b.func1(13);
    cout << b << endl;
    cout << p << endl;

    return 0;
}