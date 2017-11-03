#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define oops(m) do {perror(m); exit(1);}while(0)
#define err_quit(m) do {perror(m); exit(-1);}while(0)
#define SA struct sockaddr

typedef struct work
{
	struct sockaddr_in cliaddr;
	int clifd;
//	void * arg;
	struct work *next;
} work_t;

typedef struct work_queue
{
	struct work* head;
	struct work* tail;
	int max_size;
	int cur_size;
} work_queue_t;

typedef struct thread_pool
{
	pthread_t* tarr;
	int max_size;
	struct work_queue* work_queue;
	pthread_mutex_t mutex;
	pthread_cond_t cond_notempty;
	pthread_cond_t cond_notfull;
	int running;
} tpool_t;

void tpool_init(tpool_t* tpool, int psize, int qsize);
void tpool_add_work(tpool_t* tpool, struct sockaddr_in, int );
FILE *myopen(char *cmd);




