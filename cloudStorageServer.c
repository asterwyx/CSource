#include<stdio.h>
#include<stdlib.h>
#include<string.h>  //strlen
#include<sys/socket.h>
#include<arpa/inet.h>  //inet_addr
#include<netdb.h>
#include<errno.h>
#include<sys/epoll.h>
#include<pthread.h>

const int BUF_SIZE = 100;
const int EPOLL_SIZE = 100;  // epoll的最大数量定义为100

typedef struct sockaddr_in sockaddr_in;

typedef struct thread_args
{
	int *epfd;
	struct epoll_event *ep_events;
	int *triggered_num;
}thread_args;

void wait_for_trigger(thread_args *args);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


int main(int argc, char *argv[])
{
	int serv_sock;
	int client_sock;
	sockaddr_in serv_addr;
	sockaddr_in client_addr;
	char *message;
	
	//创建一个监听用的socket
	serv_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
	{
		printf("未能成功创建一个监听socket！");
	}
	
	// serv_addr的初始化
	memset(&serv_addr, 0, sizeof(sockaddr_in));
	serv_addr.sin_family = AF_INET;  // 使用ipv4协议
	serv_addr.sin_port = htons(8888);  // 绑定端口8888
	serv_addr.sin_addr.s_addr = INADDR_ANY;  // 绑定所有的网卡ip，即监听所有ip地址

	// 绑定serv_sock和serv_addr
	if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_sock)) == -1)
	{
		printf("绑定地址失败！");
	}

	// 开始监听，最大数量为10
	if (listen(serv_sock, 10) == -1)
	{
		printf("监听开启失败！");
	}

	pthread_t wait;
	pthread_t serv_client;

	int epfd = epoll_create(EPOLL_SIZE);
	struct epoll_event event;
	struct epoll_event *ep_events;   // epoll_event缓冲区

	// 将serv_sock加到epoll_event的缓冲区
	event.events = EPOLLIN;
	event.data.fd = serv_sock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);


	// 记录激活的事件数
	volatile int triggered_num = 1;

	// 创建线程参数结构体
	thread_args args = {&epfd, ep_events, &triggered_num};

	// 创建等待线程
	pthread_create(wait, NULL, (void *)&wait_for_trigger, (void *)&args);

	// 遍历epoll_event缓冲区
	while (1)
	{
		for (int i = 0; i < triggered_num; i++)
		{
			if (ep_events[i].data.fd == serv_sock)
			{
				socklen_t adr_sz;
				client_sock = accept(serv_sock, (struct sockaddr *)&client_addr, &adr_sz);
				
			}
			
		}
		
	}
	
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
	

	
	


	
