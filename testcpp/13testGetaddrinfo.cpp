// getaddrinfo_sample.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) 
{
    struct addrinfo hints, *result, *rp;// 定义addrinfo结构体变量
    int err;                         	// getaddrinfo函数返回值
    char ipstr[INET6_ADDRSTRLEN];       // 存储IP地址字符串的缓冲区

    if (argc != 2) 
    {                    // 检查命令行参数数量是否正确
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return -1;
    }

    memset(&hints, 0, sizeof(hints));  	// 初始化hints结构体
    hints.ai_flags = 0;                 // 192.168.200.130和www.baidu.com这种的字符串都接受
    hints.ai_family = AF_UNSPEC;		// 不限制IP地址版本
    hints.ai_socktype = SOCK_STREAM;	// 使用TCP协议

    if ((err = getaddrinfo(argv[1], NULL, &hints, &result)) != 0) // 解析主机名并将结果存储在result指针中
    {  
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(err));
        return -1;
    }

    printf("IP addresses for %s:\n", argv[1]);

    for (rp = result; rp != NULL; rp = rp->ai_next) 
    {	// 遍历result指针中的所有套接字地址结构
        void *addr;
        char *ipver;

        if (rp->ai_family == AF_INET) // IPv4地址
        {	
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)rp->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } 
        else // IPv6地址
        { 				
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)rp->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        inet_ntop(rp->ai_family, addr, ipstr, sizeof(ipstr));  // 将套接字地址结构转换为IP地址字符串
        printf("  %s: %s\n", ipver, ipstr);                    // 打印IP地址和版本号
    }

    // 释放由getaddrinfo函数分配的内存
    freeaddrinfo(result);   

    return 0;    
}
