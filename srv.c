#include <poll.h>
#include "tpool.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		err_quit("usage: ./srv <ip> <port>");
	}

	char *ip = "127.0.0.1";
	short port = atoi(argv[1]);

	int clifds[512];
	int i;
	for (i = 0; i < 512; i++)
	{
		clifds[1] = -1;
	}

	int maxfd = 0;

	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd == -1)
	{
		err_quit("socket()");
	}
	maxfd = listenfd;

	struct sockaddr_in srvaddr;
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(port);
	inet_aton(ip, &srvaddr.sin_addr);

	int ret = bind(listenfd, (SA*)&srvaddr, sizeof(srvaddr));
	if (ret == -1)
	{
		err_quit("listen()");
	}
/*	
	ret = listen(listenfd, 511);
	if (ret == -1)
	{
		err_quit("listen()");
	}
*/	
	struct sockaddr_in cliaddr;
	int len = sizeof(cliaddr);

	tpool_t tpool;
	tpool_init(&tpool, 20, 100);

	while (1)
	{
		ret = listen(listenfd, 511);
		if (ret == -1)
		{
			err_quit("listen()");
		}

		int clifd = accept(listenfd, (SA*)&cliaddr, &len);
		tpool_add_work(&tpool, cliaddr, clifd);
	//	printf("Debug srv.c add_work");
	
	}

}






