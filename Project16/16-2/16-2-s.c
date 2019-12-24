#ifndef COMMUNICAITON_TCPSOCKET_H
#define COMMUNICAITON_TCPSOCKET_H
#include <stdio.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#endif //COMMUNICAITON_TCPSOCKET_H
void tcpServerStart();

#include "TCPSocket.h"
const int bufferSize = 1024;

void tcpServerStart(){
    printf("server socket start init...\n");
    int server_socketfd;//服务器套接字
    int client_socketfd;//客户端套接字
    int port = 8000;
    struct sockaddr_in my_addr;//服务器网络地址结构
    struct sockaddr_in remote_addr;//虚拟网络地址结构
    socklen_t sin_size;//此处须运用长度定义类型 socketlen_t
    char buf[bufferSize];//数据缓冲区
    long sendLen = 0;//发送接收长度
    memset(&my_addr,0,sizeof(my_addr));//数据初始化
    my_addr.sin_family=AF_INET;//设置为IP通信
    my_addr.sin_addr.s_addr=INADDR_ANY;//服务器ip
    my_addr.sin_port=htons(port);//设置端口为8000

    /*创建服务器端套接字--IPv4协议，TCP协议*/
    if((server_socketfd = socket(PF_INET,SOCK_STREAM,0))<0){
        perror("socket init error");
        return ;
    }
    /*将套接字绑定到服务器的网络地址上*/
    if(bind(server_socketfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))<0){
        perror("bind socket error");
        return;
    }
    printf("server socket start listen ,port:%d",port);
    /*监听连接请求--监听队列长度为5*/
    listen(server_socketfd,5);

    sin_size = sizeof(struct sockaddr_in);

    /*等待客户端连接请求到达*/
    client_socketfd=accept(server_socketfd, (struct sockaddr *)&remote_addr,&sin_size);
    if(client_socketfd < 0){
        perror("listen error");
        return;
    }
    printf("accept %s",inet_ntoa(remote_addr.sin_addr));//打印客户端ip地址


    sendLen=send(client_socketfd,"welcome to login\n",21,0);//发送欢迎信息
    if(sendLen <= 0){
        perror("no send");
        return;
    }
    while(sendLen=recv(client_socketfd, buf, bufferSize, 0)>0){
        printf("accept msg===");
        printf("%s/n",buf);
    }
    close(client_socketfd);
    close(server_socketfd);


}
