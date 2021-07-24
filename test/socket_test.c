//
// Created by 李延 on 2021/7/24.
//

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/event.h>

#define PORT 9200
#define SIZE 1024   //定义的数组大小
//https://blog.csdn.net/qq_41725312/article/details/90375742
/**
 *
 * 服务端
 * @return
 */
int server_socket()    //创建套接字和初始化以及监听函数
{
    //af ,地址族（Address Family）,常用AF_INET(IPv4) 和 AF_INET6(IPv6)。
    //type ,数据传输方式，常用的有 SOCK_STREAM(面向连接)和 SOCK_DGRAM(无连接)
    //protocol 表示传输协议，常用的有 IPPROTO_TCP(TCP协议) 和 IPPTOTO_UDP(UDP协议)
    int listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);   //创建一个负责监听的套接字
    if (listen_socket == -1) {
        perror("socket");
        return -1;
    }
    //struct sockaddr_in{
    //    sa_family_t     sin_family;   //地址族（Address Family），也就是地址类型
    //    uint16_t        sin_port;     //16位的端口号
    //    struct in_addr  sin_addr;     //32位IP地址
    //    char            sin_zero[8];  //不使用，一般用0填充
    //};
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));//每个字节都用0填充

    addr.sin_family = AF_INET;  /* Internet地址族 使用IPv4地址*/
    addr.sin_port = htons(PORT);  /* 端口号 */
    addr.sin_addr.s_addr = htonl(INADDR_ANY);   /* IP地址 */
    //将套接字与特定的IP地址和端口绑定起来
    int ret = bind(listen_socket, (struct sockaddr *) &addr, sizeof(addr));  //连接
    if (ret == -1) {
        perror("bind");
        return -1;
    }
    //sock 需要进入监听状态的套接字
    //backlog 请求队列的最大长度
    //套接字进入被动监听状态
    ret = listen(listen_socket, 20);        //监听
    if (ret == -1) {
        perror("listen");
        return -1;
    }

    struct sockaddr_in cliaddr;
    int addrlen = sizeof(cliaddr);
    printf("等待客户端连接。。。。\n");
    //套接字进入被动监听状态
    //sock 为服务器端套接字
    //addr 为 sockaddr_in 结构体变量
    //addrlen 为参数 addr 的长度，可由 sizeof() 求得
    int client_socket = accept(listen_socket, (struct sockaddr *) &cliaddr, &addrlen);
    if (client_socket == -1) {
        perror("accept");
        return -1;
    }
    printf("成功接收到一个客户端：%s\n", inet_ntoa(cliaddr.sin_addr));


    //接受请求
    char buf[SIZE];
    while (1) {
        //读取数据
        //fd 为要写入的文件的描述符
        //buf 为要写入的数据的缓冲区地址
        //nbytes 为要写入的数据的字节数。
        int ret = read(client_socket, buf, SIZE - 1);
        if (ret == -1) {
            perror("read");
            break;
        }
        if (ret == 0) {
            break;
        }
        buf[ret] = '\0';
        int i;
        for (i = 0; i < ret; i++) {
            buf[i] = buf[i] + 'A' - 'a';
        }

        printf("%s\n", buf);
        write(client_socket, buf, ret);

        if (strncmp(buf, "end", 3) == 0) {
            break;
        }
    }
    close(client_socket);


    return 0;
}

int main() {
    int listen_socket = server_socket();

    return 0;
}

int test() {
    const static int FD_NUM = 2;// 要监视多少个文件描述符

    int kq = kqueue(); // kqueue对象

// kqueue的事件结构体，不需要直接操作
    struct kevent changes[FD_NUM]; // 要监视的事件列表
    struct kevent events[FD_NUM]; // kevent返回的事件列表（参考后面的kevent函数）

    int stdin_fd = STDIN_FILENO;
    int stdout_fd = STDOUT_FILENO;

// 在changes列表中注册标准输入流的读事件 以及 标准输出流的写事件
// 最后一个参数可以是任意的附加数据（void * 类型），在这里给事件附上了当前的文件描述符，后面会用到
    EV_SET(&changes[0], stdin_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, &stdin_fd);
    EV_SET(&changes[1], stdout_fd, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, &stdin_fd);

// 进行kevent函数调用，如果changes列表里有任何就绪的fd，则把该事件对应的结构体放进events列表里面
// 返回值是这次调用得到了几个就绪的事件 (nev = number of events)
    int nev = kevent(kq, changes, FD_NUM, events, FD_NUM, NULL); // 已经就绪的文件描述符数量
    for (int i = 0; i < nev; i++) {
        struct kevent event = events[i]; // 一个个取出已经就绪的事件

        int ready_fd = *((int *) event.udata); // 从附加数据里面取回文件描述符的值
        if (ready_fd == stdin_fd) {
            // 读取ready_fd
        } else if (ready_fd == stdin_fd) {
            // 写入ready_fd
        }
    }

}