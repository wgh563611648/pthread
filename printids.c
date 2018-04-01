#include "my_pthread.h"

pthread_t pthread_id;

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid=%d, tid=%ld\n", s, pid, tid);
}
void *thr_fn(void *arg)
{
	printids("new thread: ");
	return (void *)0;
}

int main(int argc, char *argv[])
{
	int creat_thread_result;
	creat_thread_result = pthread_create(&pthread_id, NULL, thr_fn, NULL);
	if(creat_thread_result != 0)
	{
		printf("can't create thread\n");
		exit(-1);
	}
	else
	{
		printf("creat_thread_result SUCCESS!\n");    
	}

	printids("main thread: ");
	sleep(1);
	return 0;
}
