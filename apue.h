#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define oops(m) do {perror(m); exit(1);} while(0)
#define err_quit(m) do {perror(m);exit(-1);} while(0)
#define SA struct sockaddr
