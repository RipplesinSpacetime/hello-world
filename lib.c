#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

#define err_quit(m) do {fprintf(stdout, m); return -1;} while(0)

int readn(int fd, void* dest, int n)
{
	int ret;
	int nleft = n;
	char * p = dest;

	while ((ret = read(fd, p, nleft)) != 0)	
	{
		if (ret > 0)
		{
			nleft -= ret;
			p += ret;
		}
		else if (ret == -1 && errno == EINTR)
			continue;
		else
			err_quit("read error\n");
	}

	return n-nleft;
}

int writen(int fd, void* from, int n)
{
	int nleft = n;
	char * p = from;
	int ret = 0;

	while (nleft > 0)
	{
		ret = write(fd, p, nleft);
		if (ret == -1 && errno == EINTR)
			continue;
		else if (ret == -1)
			err_quit("write error");

		nleft -= ret;
		p += ret;
	}

	return n-nleft;
}

int readline(int fd, void* dest, int max_num)
{
	int nleft = max_num;
	int ret = 0;
	char c = 0;
	char * p = dest;

	while (nleft > 0)
	{
		ret = read(fd, &c, 1);
		if (ret == 1)	// success, read a char
		{
			if (c == '\n')
			{
				*p = 0;
				break;
			}

			*p++ = c;
		}
		else if (ret == 0)	// success , read EOF
		{
			*p = 0;
			break;
		}
		else if (ret == -1 && errno == EINTR)	// error
		{
			continue;
		}
		else					// error
			err_quit("read");

		nleft--;
	}

	return max_num - nleft;
}




















