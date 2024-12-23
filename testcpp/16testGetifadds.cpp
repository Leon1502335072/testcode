#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

int main()
{
    sockaddr_in addrIPv4;
    struct ifaddrs *ifaddr, *ifptr;
    if (getifaddrs(&ifaddr) == -1) 
    {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifptr = ifaddr; ifptr != NULL; ifptr = ifptr->ifa_next)
    {
        if(ifptr->ifa_addr->sa_family==AF_INET)
        {
            addrIPv4 = *((sockaddr_in *)ifptr->ifa_addr);
        }
    }

    cout << "------------------------------- " << endl;
    // 这种网卡的ip拿到就是默认的大端
    addrIPv4.sin_addr.s_addr = ntohl(addrIPv4.sin_addr.s_addr);
    
    cout << "addrIPv4.sin_addr.s_addr : "
         << ((addrIPv4.sin_addr.s_addr >> 24) & 0xff) << "."
         << ((addrIPv4.sin_addr.s_addr >> 16) & 0xff) << "."
         << ((addrIPv4.sin_addr.s_addr >> 8) & 0xff) << "."
         << (addrIPv4.sin_addr.s_addr & 0xff) << endl;
    cout << "addrIPv4.sin_family: " << addrIPv4.sin_family << endl;
    cout << "addrIPv4.sin_port: " << addrIPv4.sin_port << endl;

    freeifaddrs(ifaddr);
    return 0;
}