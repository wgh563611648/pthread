#include "my_pthread.h"

typedef struct _foo
{
	int a;
	int b;
	int c;
	int d;
}FOO;

void printfoo(const char *s, FOO *fp)
{
	printf("%s at 0x%lx\n",s, (unsigned long)fp);
	printf("foo.a = %d\n", fp->a);
	printf("foo.b = %d\n", fp->b);
	printf("foo.c = %d\n", fp->c);
	printf("foo.d = %d\n", fp->d);
}

void *f1(void *arg)
{
	FOO foo={1,2,3,4};
	printfoo("thread 1", &foo);
	pthread_exit((void *)&foo);
}

void *f2(void *arg)
{
	printf("thread 2: ID is %ld\n", pthread_self());
	pthread_exit((void *)2);
}

int main(int argc, char *argv)
{
	int err;
	pthread_t th1, th2;
	FOO *foo;
	
	err = pthread_create(&th1, NULL, f1, NULL);
	if(err != 0)
	{
		printf("create thread 1 error\n");
		exit(-1);
	}

	err = pthread_join(th1, (void *)&foo);
	if(err != 0)
	{
		printf("join thread 1 error\n");
		exit(-1);
	}
	sleep(1);

	printf("start thread 2\n");
	err = pthread_create(&th2, NULL, f2, NULL);
	if(err != 0)
	{
		printf("create thread 2 error\n");
		exit(-1);
	}
	sleep(1);
	printfoo("parent:", foo);
	return 0;
}
