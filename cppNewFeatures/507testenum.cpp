#include <iostream>
#include <string>
using namespace std;

// char表示该类型只占一个字节
enum class color : char {red, green, black, white, yellow};
void fun(color c) {}

// 匿名联合体做类成员
struct Foreigner
{
    Foreigner(string ad, string p):addr(ad), phone(p) {}
    string addr;
    string phone;
};

class Person
{
public:
    enum class Category : char
    {
        student,
        local,
        foreign
    };
    Person(int num):inSchoolNum(num), c(Category::student) {}
    Person(string lp):localIdNum(lp), c(Category::local) {}
    Person(string a, string p):fore(a, p), c(Category::foreign) {}
    ~Person() {}

    void print()
    {
        switch (c)
        {
        case Category::student:
            cout << "Student school number: " << inSchoolNum << endl;
            break;
        case Category::local:
            cout << "Local people ID number: " << localIdNum << endl;
            break;
        case Category::foreign:
            cout << "Foreigner address: " << fore.addr
                << ", phone: " << fore.phone << endl;
            break;
        }
    }

private:
    Category c;
    union
    {
        int inSchoolNum;
        string localIdNum;
        Foreigner fore;
    };
};

int main(int arg, char* argv[])
{
    Person p1(20201002);
    Person p2("332224200110020306");
    Person p3("南京江宁中海国际一期", "13033658892");
    p1.print();
    p2.print();
    p3.print();

    // // fun(0); c++11之后不允许这样写，需要显示类型转换 (color)0 (color)1 不能是(color::)0 这种事错误的
    // fun((color)0);

    // // c++11之后就需要显示类型转换了
    // cout << "color is " << (int) color::green << endl;
    // cout << "sizeof(color): " << sizeof(color::white) << endl;



    return 0;
}