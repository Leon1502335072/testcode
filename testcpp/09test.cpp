#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fstream>
using namespace std;

#define print(fmt, ...) printf(fmt, __VA_ARGS__)

static thread_local int val = 0;

class Base
{
public:
    Base()
    {
        pthread_mutex_init(&mutext, NULL);
    }
    // void fun()
    // {
    //     pthread_mutex_lock(&mutext);
    //     for (int i = 0; i < 100000; ++i)
    //     {
    //         m_a++;
    //     }
    //     cout << "m_a = " << m_a << endl;
    //     pthread_mutex_unlock(&mutext);
    // }
    void fun()
    {
        
        for (int i = 0; i < 100000; ++i)
        {
            pthread_mutex_lock(&mutext);
            m_a++;
            pthread_mutex_unlock(&mutext);
        }
        cout << "m_a = " << m_a << endl;
        
    }

    void fun1()
    {
        if(m_fileStream)
        {
            cout << "cun zai" << endl;
            m_fileStream.close();
        }
        else
        {
            cout << "no cun zai" << endl;
        }
    }

    ~Base()
    {
        pthread_mutex_destroy(&mutext);
    }
private:
    int m_a = 0;
    pthread_mutex_t mutext;
    ofstream m_fileStream;
};

int a = 0;
Base b, b1;

void* func1(void* arg)
{
    b.fun();
    return NULL;
}

void* func2(void* arg)
{
    b1.fun();
    return NULL;
}

void* func3(void* arg)
{
    for (int i = 0; i < 100000; i++)
    {
        //usleep(10);
        a++;
    }
}



int main()
{
    Base b1, b2;
    pthread_t t1, t2;
    pthread_create(&t1, nullptr, func1, nullptr);
    pthread_create(&t2, nullptr, func1, nullptr);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    print("%d\n", 10);
    print("hello world\n", 1);

    b1.fun1();
    auto m = 10;

    cout <<"a: "<< a << endl;
    return 0;
}