#include<stdio.h>
#include<sys/epoll.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#pragma pack(1)  // 单字节对齐

#define OPR_SIZE 20
#define MAX_EVENTS 1024
#define BUF_SIZE 4096
#define SERV_PORT 8888
#define NAME_SIZE 128
#define POOL_NUM 5
#define RCV_SIZE BUF_SIZE+NAME_SIZE+24

typedef struct MyEvent{
    int fd;             // 文件描述符
    int events;         // 对应的监听事件
    void *arg;         // 泛型参数，用于指向结构体自己
    void (*call_back)(int fd, int events, void *arg);
    int status;
    long last_active;
} MyEvent;