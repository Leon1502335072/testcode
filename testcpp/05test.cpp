#include <iostream>
#include <unistd.h>
using namespace std;

void fun2()
{
    cout << " fun2" << endl;
    return;
}

void fun()
{
	while (1)
	{
		sleep(2);
		cout << "goto here while !" << endl;
		fun2();
	}
	cout << "goto here out of while !" << endl;
	return ;
}


int main()
{
	fun();



	return 0;
}