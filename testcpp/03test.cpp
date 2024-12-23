#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include "/Coroutines/sylar-from-scratch/sylar/endian.h"
#include "/Coroutines/sylar-from-scratch/sylar/address.h"



struct sockaddr_un_new
{
	uint16_t sun_family;
	char sun_path[108]; /* Path name. */
};
template <class T>
static T CreateMask(uint32_t bits) 
{
    return (1 << (sizeof(T) * 8 - bits)) - 1;
}

std::ostream& insert(std::ostream &os, uint32_t ip) 
{
    uint32_t addr = sylar::byteswapOnLittleEndian(ip);
    std::cout << "addr: " << addr << std::endl;
    // 例如10.0.3.193这个地址在计算机里就是一个uint_32类型的整数167773121 通过位运算转化
    os << ((addr >> 24) & 0xff) << "."
       << ((addr >> 16) & 0xff) << "."
       << ((addr >> 8) & 0xff) << "."
       << (addr & 0xff);
    return os;
}

std::string toString(uint32_t ip)
{
    std::stringstream ss;
    insert(ss, ip);
    return ss.str();
}
int main()
{
    std::cout << sizeof(((sockaddr_un_new *)0)->sun_path) - 1 << std::endl;
    std::cout << sizeof((sockaddr_un_new *)0)<< std::endl;

    // 
    std::cout << "---------------------------------------------" << std::endl;
    uint32_t len = 24;
    std::cout << "CreateMask<uint32_t>(24): " << CreateMask<uint32_t>(len) << std::endl;
    std::cout << "取反之前: " << sylar::byteswapOnLittleEndian(CreateMask<uint32_t>(len))<< std::endl;
    uint32_t ip = ~sylar::byteswapOnLittleEndian(CreateMask<uint32_t>(len)); 
    std::cout << "取反之后: "<<ip << std::endl;

    std::cout << toString(ip) << std::endl;

    
    std::cout << "---------------------------------------------" << std::endl;



    std::cout << offsetof(sockaddr_un_new, sun_path) + 127 << std::endl;
    // 计算机是小端的 byteswapOnLittleEndian是转大端 
    uint32_t p = 255;
    uint32_t p1 = sylar::byteswapOnLittleEndian(p);
    std::cout << p1 << std::endl;
    uint32_t p2 = sylar::byteswapOnLittleEndian(p1);
    std::cout << p2 << std::endl;
    std::cout << htonl(p) << std::endl;
    std::cout << sylar::byteswapOnBigEndian(p) << std::endl;


    std::cout << "---------------------------------------------" << std::endl;

    char* ll = new char[10];
	int* pp = (int* )malloc(sizeof(int));
    int arr[] = {1, 2, 3, 4, 5, 6};
    // 指针大小 都是8字节
    std::cout << "sizeof(ll): " << sizeof(ll) << std::endl;
    std::cout << "sizeof(pp): " << sizeof(pp) << std::endl;
    std::cout << "sizeof(arr): " << sizeof(arr) << std::endl;
    std::cout << "sizeof(*ll): " << sizeof(*ll) << std::endl;
    std::cout << "sizeof(*pp): " << sizeof(*pp) << std::endl;
    std::cout << "sizeof(*arr): " << sizeof(arr) << std::endl;
    return 0;
}