#include <iostream>
#include <list>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void* fun(void * arg)
{
    int a = 10;
    cout << "thread_" << pthread_self() << ": a=" << a << endl;
    a+=5;
    sleep(10);
}

int main()
{
    list<int> ls;
    for (int i = 0; i < 1; ++i)
    {
        ls.push_back(i);
        cout << "ls.size(): " << ls.size() << endl;
    }
    auto it = ls.begin();
    ls.erase(it++);
    cout << *it << endl;

    pthread_t t1, t2;
    pthread_create(&t1, NULL, fun, NULL);
    sleep(3);
    pthread_create(&t2, NULL, fun, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}