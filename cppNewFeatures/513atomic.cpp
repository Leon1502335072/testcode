#include <iostream>
#include <atomic>
#include <string>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;

struct Person
{
    Person(int a, string n) : age(a), name(n) {}
    int age;
    string name;
};

class Counter
{
public:
    Counter():number(0) {}
    void increment()
    {
        for (int i = 0; i < 100; ++i)
        {
            //mtx.lock();
            number++;
            cout << "+++ increment thread id: " << this_thread::get_id() 
                << ", number: " << number << endl;
            //mtx.unlock();
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    void increment1()
    {
        for (int i = 0; i < 100; ++i)
        {
            //mtx.lock();
            number++;
            cout << "*** decrement thread id: " << this_thread::get_id()
                << ", number: " << number << endl;
            //mtx.unlock();
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }
private:
    //int number = 0;
    atomic_int number;
    //mutex mtx;
};

int main(int arg, char *argv[])
{
    atomic<char> c1('a');
    atomic_char c2('b');

    atomic<int> b1(9);
    atomic<int> b2;
    atomic_init(&b2, 100);

    c1 = 'd';
    b1.store(10);
    auto cc = c2.exchange('j');

    Person p(18, "luffy");
    // 这点在多线程情况下并不能保证p里的数据是安全的，只能保证地址的++，--操作是安全的 并不能保证地址里的数据是安全的
    atomic<Person *> ato_p(&p);

    cout << "c1 = " << c1 << endl;
    cout << "b1 = " << b1.load() << endl;
    cout << "age = " << ato_p.load()->age << ", name = " << ato_p.load()->name << endl;
    return 0;
}