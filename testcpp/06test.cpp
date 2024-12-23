#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <iostream>
using namespace std;



int main(int argc, char* argv[])
{
    int listenfd = socket( PF_INET, SOCK_STREAM, 0 );

    int ret = 0;
    struct sockaddr_in address;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_family = AF_INET;
    address.sin_port = htons(1002);

    // 端口复用 + 绑定
    int reuse = 1;
    setsockopt( listenfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof( reuse ) );
    ret = bind( listenfd, ( struct sockaddr* )&address, sizeof( address ) );
    if(ret == -1)
    {
        perror("bind");
    }
    ret = listen( listenfd, 5 );
    while(1)
    {
        cout << "here" << endl;
        if(ret == -1)
        {
            perror("listen");
        }
        struct sockaddr_in client_address;
        socklen_t client_addrlength = sizeof( client_address );
        int connfd = accept( listenfd, ( struct sockaddr* )&client_address, &client_addrlength );
        cout << "connfd: " << connfd << endl;
        if (connfd < 0)
        {
            std::cout << "connfd error" << std::endl;
            continue;
        }
        char recvbuff[4096];
        ssize_t recount = recv(connfd, recvbuff, 4096, 0);
        cout << recv << endl;

        const char *buff = "HTTP/1.1 404 Not Found\r\n"
                           "Connection: close\r\n"
                           "Content-Length: 136\r\n\r\n"
                           "<html><head><title>404 Not Found</title></head><body><center><h1>404 Not Found</h1></center><hr><center>sylar/1.0</center></body></html>";
        ssize_t rt = send(connfd, buff, sizeof(buff), 0);
        //close(connfd);
    }

    close(listenfd);
    return 0;
}
