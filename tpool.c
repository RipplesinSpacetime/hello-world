uinclude <stdio.h>

#include "tpool.h"

char buf[512] = {0};

static work_queue_t * __work_queue_init(int max_size)
{
	work_queue_t *queue = (work_queue_t *)malloc(sizeof(work_queue_t));
	queue->head = NULL;
	queue->tail = NULL;
	queue->max_size = max_size;
	queue->cur_size = 0;
}

void * running(void *arg)
{
	tpool_t* tpool = (tpool_t*)arg;

	while(tpool->running)
	{
		pthread_mutex_lock(&(tpool->mutex));

		while (tpool->work_queue->cur_size == 0)
		{
			pthread_cond_wait(&(tpool->cond_notempty), &(tpool->mutex));
		}
		work_t* cur_work = tpool->work_queue->head;
		if (cur_work == NULL)
			printf("cur_work is NULL\n");

		tpool->work_queue->head = tpool->work_queue->head->next;
		tpool->work_queue->cur_size--;

		pthread_cond_broadcast(&(tpool->cond_notfull));
		pthread_mutex_unlock(&(tpool->mutex));

		printf("connected from %s %hu\n",inet_ntoa(cur_work->cliaddr.sin_addr),
										 ntohs(cur_work->cliaddr.sin_port));
//here:	
		int n = 1;
		while(n != 0)
		{
			
			//printf("Debug 45 twice\n");
			n = read(cur_work->clifd, buf, 512);//出错！停留此处！
			//printf("Debug 47 twice\n");
			printf("%s\n",buf);

			if (n == -1)
			{
				perror("read()");
				exit(1);
			}
			else if (n == 0)
			{
				printf("connect from %s %hu is shutdown\n",
							inet_ntoa(cur_work->cliaddr.sin_addr),
							ntohs(cur_work->cliaddr.sin_port));

		 		close(cur_work->clifd);

			}
			else 
			{
				if (buf[0] == 'g' && buf[1] == 'e' && buf[2] == 't') //if判断写在这里有问题，执行一次get之后就无法再执行
				{													// 原因未知！
					int pid = 0;
					if ((pid = fork()) == 0)
					{
						int a = 0;
						int b = 0;
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
						printf("copy %s\n", buffname);

						FILE *in;
						if ((in = fopen(buffname, "r")) == NULL)
						{
							printf("cannot open file!\n");
							char buf1[] = "   file does not exist!";
							buf1[0] = 0;
							write(cur_work->clifd, buf1, sizeof(buf1));
						//	fwrite(fdopen(cur_work->clifd, "r"), sizeof(buf1), 1, fileno(buf1));
						}
						else
						{
							fseek(in, 0, SEEK_END);
							long fsize = ftell(in);
							fseek(in, 0, SEEK_SET);

							char buf1[fsize+3];
							memset(buf1, 0, fsize+3);
							buf1[0] = 1;
							buf1[1] = fsize/128;
							buf1[2] = fsize%128;
							fread(buf1+3, fsize, 1, in);
							//read(fileno(in), buf1+3, fsize);
							fclose(in);
						//	write(cur_work->clifd, buf1, fsize+3);
							write(cur_work->clifd, buf1, fsize+3);
						//	fwrite(fdopen(cur_work->clifd, "r"), fsize+3, 1, fileno(buf1));
						//	*/
						/*
						    char buf1[4096] = {0};
							memset(buf1, 0, 4096);
							fread(buf1, 4096, 1, in);
							fclose(in);
							write(cur_work->clifd, buf1, 4096);
							*/
							memset(buf, 0, 512);
							printf("Deubug:write over\n");
						}
					}

					wait(NULL);

				}

				else
				{
					//printf("Debug: 130\n");
					char *p = (char *)buf;
					FILE *f = myopen(p);
					char buf1[1024] = {0};
					fread(buf1, 1024, 1, f);
				//	int ret = read(fileno(f),buf1, 1024);
					printf("%s\n",buf1);
					write(cur_work->clifd, buf1, strlen(buf1));
				//	write(cur_work->clifd, buf1, 1024);
				}

			}

			//printf("Debug:143\n");

		}

		free(cur_work);
	}

		pthread_exit(NULL);

}

void tpool_init(tpool_t* tpool, int psize, int qsize)
{
	tpool->max_size = psize;
//	printf("qsize = %d\n",qsize);
	tpool->tarr = (pthread_t *)malloc((sizeof(pthread_t))*psize);
	tpool->work_queue = __work_queue_init(qsize);
	tpool->running = 1;

	pthread_mutex_init(&(tpool->mutex), NULL);
	pthread_cond_init(&(tpool->cond_notempty), NULL);
	pthread_cond_init(&(tpool->cond_notfull), NULL);

	memset(tpool->tarr, 0, (sizeof(pthread_t))*psize);

	int i = 0;
	for (i = 0; i < psize; i++)
	{
		pthread_create(tpool->tarr+i, NULL, running, (void *)tpool);
	}

}

void tpool_add_work(tpool_t* tpool, struct sockaddr_in cliaddr,int clifd)
{
	work_t* cur_work = (work_t *)malloc(sizeof(work_t));
	cur_work->clifd = clifd;
	cur_work->cliaddr = cliaddr;
	cur_work->next = NULL;

	pthread_mutex_lock(&(tpool->mutex));
	while (tpool->work_queue->cur_size == tpool->work_queue->max_size)
	{
		pthread_cond_wait(&(tpool->cond_notfull), &(tpool->mutex));
	}

		if (tpool->work_queue->cur_size == 0)
		{
			tpool->work_queue->head = cur_work;
			tpool->work_queue->tail = cur_work;
		}
		else
		{
			tpool->work_queue->tail->next = cur_work;
			tpool->work_queue->tail = cur_work;
		}

		tpool->work_queue->cur_size++;

		pthread_cond_broadcast(&(tpool->cond_notempty));
		pthread_mutex_unlock(&(tpool->mutex));
	
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


