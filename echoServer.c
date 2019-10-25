#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/epoll.h>


const int BUF_SIZE = 100;
const int EPOLL_SIZE = 50;
void error_handing(char *message);

int main()
{
	int serv_sock;
	int client_sock;
	struct sockaddr_in serv_addr;
	struct sockaddr_in client_addr;
	serv_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
	{
		error_handing("socket() error");
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(18888);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	

	if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
	{
		error_handing("bind() error");
	}

	if (listen(serv_sock, 5) == -1)
	{
		error_handing("listen() error");
	}

	int epfd = epoll_create(EPOLL_SIZE);
	struct epoll_event event;
	struct epoll_event *ep_events = (struct epoll_event *) malloc(sizeof(event) * EPOLL_SIZE);
	
	event.events = EPOLLIN;
	event.data.fd = serv_sock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);
	while (1)
	{
		int event_client = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
		if (event_client == -1)
		{
			puts("epoll_wait() error");
		}

		for (int i = 0; i < event_client; i++)
		{
			
			if (ep_events[i].data.fd == serv_sock)
			{
				socklen_t adr_sz;
				client_sock = accept(serv_sock, (struct sockaddr_in *)&client_addr, &adr_sz);
				event.events = EPOLLIN;
				event.data.fd = client_sock;
				epoll_ctl(epfd, EPOLL_CTL_ADD, client_sock, &event);
			}
			else
			{
				char buf[BUF_SIZE];
				int str_len = read(ep_events[i].data.fd, buf, BUF_SIZE);
				if (str_len == 0)
				{
					epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
					close(ep_events[i].data.fd);
					printf("closed client: %d \n", ep_events[i].data.fd);
				}
				else
				{
					write(ep_events[i].data.fd, buf, str_len);
				}
			}
		}
	}
	close(serv_sock);
	close(epfd);
	return 0;
}


