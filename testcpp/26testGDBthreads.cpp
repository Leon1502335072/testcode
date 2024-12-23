#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void* fun1(void *arg)
{
    int n = 0;
    while (1)
    {
        n++;
        cout << "I am thread_1, ID: " << pthread_self() << "---" << n << endl;
        sleep(5);
    }
}

void* fun2(void *arg)
{
    int n = 0;
    while (1)
    {
        n++;
        cout << "I am thread_2, ID: " << pthread_self() << "---" << n << endl;
        sleep(5);
    }
}

int main()
{
    pthread_t th1;
    pthread_t th2;

    pthread_create(&th1, NULL, fun1, NULL);
    pthread_create(&th2, NULL, fun2, NULL);

    cout << "I am main thread, ID: " << pthread_self() << endl;

    pthread_join(th1, NULL);
    pthread_join(th1, NULL);
    return 0;
}