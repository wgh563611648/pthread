#include "my_pthread.h"

void *thr_fn1(void *arg)
{
	printf("pthread 1\n");
	return ((void *)1);
}

void *thr_fn2(void *arg)
{
	printf("pthread 2\n");
	pthread_exit((void *)2);
}

int main(int argc, char *argv[])
{
	int err;
	pthread_t th1;
	pthread_t th2;
	void *tret;

	err = pthread_create(&th1, NULL, thr_fn1, NULL);
	if(err != 0)
	{
		printf("create thread 1 error\n");
		exit(-1);
	}
	
	err = pthread_create(&th2, NULL, thr_fn2, NULL);
	if(err != 0)
	{
		printf("create thread 2 error\n");
		exit(-1);
	}

	err = pthread_join(th1, &tret);
	if(err != 0)
	{
		printf("join thread 1 error\n");
		exit(-1);
	}
	printf("thread 1 exit code is: %ld\n", (long)tret);

	err = pthread_join(th2, &tret);
	if(err != 0)
	{
		printf("join thread 2 error\n");
		exit(-1);
	}
	printf("thread 2 exit code is: %ld\n", (long)tret);

	return 0;
}
