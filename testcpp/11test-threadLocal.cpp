#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fstream>
#include <memory>
using namespace std;

#define print(fmt, ...) printf(fmt, __VA_ARGS__)

static thread_local int val = 0;


int a = 0;


void* func1(void* arg)
{
    for (int i = 0; i < 2000000; ++i)
    {
        val++;
    }
    cout << "child thread-1: " << val << endl;
    ;
    return NULL;
}

void* func2(void* arg)
{
    for (int i = 0; i < 3000000; ++i)
    {
        val++;
    }
    cout << "child thread-2: " << val << endl;
    
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
    shared_ptr<int> p(new int(10));
    shared_ptr<int> p2;
    p2.swap(p);
    if (p)
    {
        cout <<"p的地址: " <<p << endl;
        cout << *p << endl;
    }
    else
    {
        cout <<" p不存在 "<< endl;
    }

    pthread_t t1, t2;
    pthread_create(&t1, nullptr, func1, nullptr);
    pthread_create(&t2, nullptr, func2, nullptr);
    for (int i = 0; i < 1000000; ++i)
    {
        val++;
    }
    cout << "main thread: " << val << endl;
    ;

    pthread_join(t1, NULL);
    pthread_join(t2, NULL); 
    return 0;
}