#include <poll.h>
#include "tpool.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		fprintf(stdout, "usage: <ip> <port>\n");
		return 0;
	}

	char *ip = "127.0.0.1";
	short port = atoi(argv[1]);

	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		err_quit("sockst()");
	}

	struct sockaddr_in srvaddr;
	memset(&srvaddr, 0, sizeof(srvaddr));

	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(port);
	if (inet_aton(ip, &srvaddr.sin_addr) == 0)
	{
		err_quit("inet_aton");
	}

	int ret;
	ret = connect(sockfd, (SA*)&srvaddr, sizeof(srvaddr));
	if (ret == -1)
	{
		err_quit("connect");
	}

	char sndbuf[512] = {0};
	char rcvbuf[512] = {0};

	struct pollfd fds[2];

	fds[0].fd = 0;
	fds[0].events = POLLIN;
	fds[1].fd = sockfd;
	fds[1].events = POLLIN;

	int events = 0;
	while(1)
	{
		events = poll(fds, 2, -1);
		if (events == -1)
		{
			perror("poll()");
			exit(1);
		}

		if (fds[0].revents & POLLIN)
		{
			fgets(sndbuf, sizeof(sndbuf)-1, stdin);

			write(sockfd, sndbuf, strlen(sndbuf));

			if (--events == 0)
				continue;
		}

		if (fds[1].revents & POLLIN)
		{
			if (sndbuf[0] == 'g' && sndbuf[1] == 'e' && sndbuf[2] == 't')
			{
				int a = 0;
				int b = 0;
				while (sndbuf[4+b] != '\n')
				{
					a++;
					b++;
				}

				char buffname[a+1];
				buffname[a] = '\0';
				for (b = 0; b < a; b++)
				{
					buffname[b] = sndbuf[4+b];
				}

				char buf0[3] = {0};
				read(sockfd, buf0, 3);

				if (buf0[0] == 0)
				{
					char buf1[128] = {0};
					read(sockfd, buf1, 128);
					//fgets(buf1, 128, fdopen(sockfd, "r"));
					printf("%s\n",buf1);
					continue;
				}

				else if(buf0[0] == 1)
				{
					int fsize = buf0[1]*128 + buf0[2];
					printf("fsize = %d\n",fsize);
					FILE *out = fopen(buffname,"a+");
					char buf2[fsize+3];
					memset(buf2, 0, sizeof(buf2));

					read(sockfd, buf2, fsize+3);
				//	fgets(buf2, fsize+3, fdopen(sockfd, "r"));
					write(fileno(out), buf2, fsize);//+2
				//	fwrite(buf2, fsize, 1, out);
					printf("the file of %s has already been copied to ./\n",buffname);
					//printf("Debug: copy over\n");
				}

				continue;


			}

		//	printf("Debug: 118 copy next\n");
			ret = read(sockfd, rcvbuf, sizeof(rcvbuf)-1);
			//FILE *f = fgets(rcvbuf, sizeof(rcvbuf)-1, fdopen(sockfd, "r"));
			if (ret == -1)
			{
				perror("read");
				exit(1);
			}
			else if (ret == 0)
			{
				printf("server is shutdown,connection disconnet\n");
				exit(1);
			}
		
			rcvbuf[ret] = 0;

			printf("%s\n",rcvbuf);
		}
	}

	return 0;

}




