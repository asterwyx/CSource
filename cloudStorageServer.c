#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //strlen
#include <sys/socket.h>
#include <arpa/inet.h>  //inet_addr
#include <netdb.h>
#include <errno.h>
#include <sys/epoll.h>
#include <pthread.h>
#include <unistd.h>

const int BUF_SIZE = 1024;
const int EPOLL_SIZE = 1024;  // epoll的最大数量定义为100

typedef struct sockaddr_in sockaddr_in;

typedef struct thread_args
{
	int *epfd;
	struct epoll_event *ep_events;
	int *triggered_num;
} thread_args;

typedef struct efddata
{
    void *ptr;
    int fd;
    uint64_t len;
}efd_data;

void wait_for_trigger(thread_args *args);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


int main(int argc, char *argv[])
{
	int serv_sock;
	int client_sock;
	sockaddr_in serv_addr;
	sockaddr_in client_addr;

	
	//创建一个监听用的socket
	serv_sock = socket(AF_INET, SOCK_STREAM, 0);  // 这里使用SOCK_NONBLOCK是指用了之后该流就变成一个非阻塞流了吗？
	if (serv_sock == -1)
	{
		printf("未能成功创建一个监听socket！\n");
	}
    int on = 1;
	setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	// serv_addr的初始化
	memset(&serv_addr, 0, sizeof(sockaddr_in));
	serv_addr.sin_family = AF_INET;  // 使用ipv4协议
	serv_addr.sin_port = htons(18888);  // 绑定端口8888
	serv_addr.sin_addr.s_addr = htons(INADDR_ANY);  // 绑定所有的网卡ip，即监听所有ip地址

	// 绑定serv_sock和serv_addr
	if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
	{
		printf("绑定地址失败！\n");
	}

	// 开始监听，最大数量为10
	if (listen(serv_sock, 10) == -1)
	{
		printf("监听开启失败！\n");
	}
    printf("Waiting for connection!\n");
	//pthread_t wait;

	int epfd = epoll_create(EPOLL_SIZE+1);
	struct epoll_event *event;
	struct epoll_event ep_events[EPOLL_SIZE + 1]; // epoll_event缓冲区
	memset(ep_events, 0, (EPOLL_SIZE + 1) * sizeof(struct epoll_event));  // 初始化缓冲区


	// 将serv_sock加到epoll_event的缓冲区
	event = (struct epoll_event*)malloc(sizeof(struct epoll_event));
	event->events = EPOLLIN;
	event->data.fd = serv_sock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, event);


	// 记录激活的事件数
	int triggered_num = 1;

	// 创建线程参数结构体
//	thread_args args = {&epfd, ep_events, &triggered_num};

	// 创建等待线程
//	pthread_create(&wait, NULL, (void *)&wait_for_trigger, (void *)&args);
//	pthread_join(wait, NULL);

	// 遍历epoll_event缓冲区
	while (1)
	{
        int num = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
        if (num == -1)
        {
            printf("获取激活的时间数量失败！");
            continue;
        }

        // 加锁
        if (pthread_mutex_lock(&mutex) != 0)
        {
            perror("pthread_mutex_lock");
            exit(EXIT_FAILURE);
        }
        triggered_num = num;
        // 解锁
        if (pthread_mutex_unlock(&mutex) != 0)
        {
            perror("pthread_mutex_unlock");
            exit(EXIT_FAILURE);
        }
		for (int i = 0; i < triggered_num; i++)
		{
			if (ep_events[i].data.fd == serv_sock)
			{
			    // 用来存储sock_addr实际长度的变量一定要初始化
				socklen_t adr_sz = sizeof(struct sockaddr);
				client_sock = accept(serv_sock, (struct sockaddr *)&client_addr, &adr_sz);
				if (client_sock < 0)
				{
					continue;
				}
				printf("已接受来自%s: %d的连接请求\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));   // 打印出新接受到的连接的ip地址和端口号，这里要进行一个网络字节序到主机字节序的转换。
				//setnonblocking(client_sock);
				// 数据缓冲区
				char *buffer = (char *)malloc(BUF_SIZE);
                event = (struct epoll_event*)malloc(sizeof(struct epoll_event));
				event->events = EPOLLIN;
				event->data.fd = client_sock;
				event->data.ptr = buffer;
				epoll_ctl(epfd, EPOLL_CTL_ADD, client_sock, event);
			}
			else if (ep_events[i].events & EPOLLIN)
            {
				int sockfd_r;
				if ((sockfd_r = ep_events[i].data.fd) < 0)
				{
					continue;
				}  // 检查文件描述符是否有效
				int strlen = recv(sockfd_r, ep_events[i].data.ptr, BUF_SIZE, 0);
				printf("Receive:%s\n",ep_events[i].data.ptr);
				if (strlen == -1)
				{
					epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
					close(ep_events[i].data.fd);
					printf("Closed client:%d\n", ep_events[i].data.fd);
				}
				else
				{
                    event = (struct epoll_event*)malloc(sizeof(struct epoll_event));
					event->data.ptr = ep_events[i].data.ptr;
					event->data.u64 = strlen;
				}
				// 修改sockfd_r上要处理的事件为EPOLLOUT
				event->events = EPOLLOUT;
				event->data.fd = sockfd_r;
				epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd_r, event);
			}
			else if (ep_events[i].events & EPOLLOUT)
			{
				int sockfdw = ep_events[i].data.fd;
                char *buffer = ep_events[i].data.ptr;
				char requestType[7] = {0};
				int n = 0;
				for (n = 0; buffer[n] != ' '; n++)
				{
					requestType[n] = buffer[n];
				}
				requestType[n] = '\0';
				printf("%s", requestType);
				send(sockfdw, requestType, strlen(requestType), 0);
                event = (struct epoll_event*)malloc(sizeof(struct epoll_event));
                event->events = EPOLLIN;
                event->data.fd = sockfdw;
                epoll_ctl(epfd, EPOLL_CTL_ADD, sockfdw, event);
			}	
		}
		
	}
	close(epfd);
	close(serv_sock);
	return 0;
}


// 处理等待激活线程函数
void wait_for_trigger(thread_args *args)
{
	while (1)
	{
		int num = epoll_wait(*(args->epfd), args->ep_events, EPOLL_SIZE, -1);
		if (num == -1)
		{
			printf("获取激活的时间数量失败！");
			continue;
		}
		// 加锁
		if (pthread_mutex_lock(&mutex) != 0)
		{
			perror("pthread_mutex_lock");
			exit(EXIT_FAILURE);
		}
		*(args->triggered_num) = num;
		// 解锁
		if (pthread_mutex_unlock(&mutex) != 0)
		{
			perror("pthread_mutex_unlock");
			exit(EXIT_FAILURE);
		}
	}
}
	

	
	


	
