#include <poll.h>

#include "apue.h"

FILE* myopen(char* cmd);

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
		clifds[i] = -1;
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

	int ret = bind(listenfd, (SA *)&srvaddr, sizeof(srvaddr));
	if (ret == -1)
	{
		err_quit("bind()");
	}

	ret = listen(listenfd, 5);
	if (ret == -1)
	{
		err_quit("listen()");
	}

	struct pollfd fds[513];
	memset(fds, 0, sizeof(fds));
	for (i = 0; i < 513; i++)
	{
		fds[i].fd = -1;
	}

	fds[0].fd = listenfd;
	fds[0].events = POLLIN;
	int maxidx = 0;

	struct sockaddr_in cliaddr;
	int len = sizeof(cliaddr);
	
	int events = 0;
	while (1)
	{
		events = poll(fds, maxidx+1, -1);
		if (events == -1)
		{
			perror("poll()");
			exit(1);
		}

		if (fds[0].revents & POLLIN)
		{
			for(i = 1; i < 513; i++)
			{
				if (fds[i].fd == -1)
					break;
			}

			if (i == 513)
			{
				printf("too many clients\n");
			}
			else
			{
				int clifd = accept(listenfd, (SA*)&cliaddr, &len);
				printf("connected from %s %hu\n", 
						inet_ntoa(cliaddr.sin_addr), 
						ntohs(cliaddr.sin_port));

				fds[i].fd = clifd;
				fds[i].events = POLLIN;

				if (i > maxidx)
					maxidx = i;
			}

			if (--events == 0)
				continue;
		}
		int n = 0;
		char buf[512] = {0};
		for (i = 1; i <= maxidx; i++) 	
		{
			if (fds[i].fd == -1)
				continue;
			printf("There are %d clients\n" ,i);
			if (fds[i].revents & POLLIN)
			{
				n = read(fds[i].fd, buf, 512);
				printf("%s\n",buf);

				if(buf[0] == 'g' && buf[1] == 'e' && buf[2] == 't')
				{
					int b = 0;
					int a = 0;
					while (buf[4+b] != '\n')
					{
						a++;
						b++;
					}
					
					char buffname[a+1];
					buffname[a] = '\0';
					for (b = 0; b < a; b++)	
					{
						 buffname[b] = buf[4+b];
					}
					printf("copy %s\n",buffname);

					FILE *in ;
					if((in = fopen(buffname,"r")) == NULL)
					{
						printf("cannot open file!\n");
						char buf1[] = "   file doesn't exist!";
						buf1[0] = 0;
						write(fds[i].fd, buf1, sizeof(buf1));
					}
					else 
					{
						fseek(in, 0, SEEK_END);
						long fsize = ftell(in);
						fseek(in, 0, SEEK_SET);

						char buf1[fsize+3] ;
						memset(buf1, 0, fsize+3);
						buf1[0] = 1;
						buf1[1] = fsize/128;
						buf1[2] = fsize%128;
						fread(buf1+3, fsize, 1, in);
					//	printf("Debug: %s\n",buf1+3);
						fclose(in);
						write(fds[i].fd, buf1, fsize+3);
					}

					continue;


				}

				if (n == -1)
				{
					perror("read()");
					exit(1);
				}
				else if (n == 0)
				{
					printf("connected from %s %hu is shutdown\n",
										inet_ntoa(cliaddr.sin_addr), 
										ntohs(cliaddr.sin_port));
					close(fds[i].fd);
					fds[i].fd = -1;
				}
				else
				{	
					char *p = (char *)buf;
					FILE *f = myopen(p);
					char buf1[512] = {0};
					fread(buf1, 512, 1, f);
					write(fds[i].fd, buf1, 512);
				}

				if (--events <= 0)
					break;
			}
		}
	}
}


FILE *myopen(char *cmd)
{
	int fd[2];
	if (pipe(fd) == -1)
	{
		oops("pipe");
	}

	int pid = 0;
	if ((pid = fork()) == -1)
		oops("fork()");

	if (pid == 0)
	{
		close(fd[0]);

		dup2(fd[1], 1);
		close(fd[1]);

		execl("/bin/sh","sh", "-c", cmd, NULL);

		oops("execl");
	}

	close(fd[1]);
	wait(NULL);

	return fdopen(fd[0], "r");

}

