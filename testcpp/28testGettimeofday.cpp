#include <iostream>
#include <stdio.h>
#include <sys/time.h>
 
int main() 
{
    struct timeval tv;
    struct timezone tz;
 
    gettimeofday(&tv, &tz);
 
    printf("Seconds: %ld\n", tv.tv_sec);
    printf("Microseconds: %ld\n", tv.tv_usec);

    std::cout << 1733151201 / 86400 << std::endl;
    return 0;
}