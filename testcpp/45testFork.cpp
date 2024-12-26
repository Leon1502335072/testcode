#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;



int main(int arg, char* argv[])
{
    printf("我是父进程, pid: %d, ppid: %d\n", getpid(), getppid());

    pid_t id = fork();
    if(id == 0)
    {
        while(1)
        {
            printf("我是子进程, pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(5);
        }

    }
    else if(id > 0)
    {
        while(1)
        {
            printf("我是父进程, pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(5);
        }
       
    }
    else
    {
        cout << "fork is error..." << endl;
    }

    return 0;
}