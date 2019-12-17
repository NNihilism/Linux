#include "my.h"

void *threadfun(void *arg)
{
	printf("thread pid = %d\n",getpid());
}

int main()
{
	pthread_t tidp;
	int error;
	error = pthread_create(&tidp,NULL,threadfun,NULL);
	if(error!=0)
	{
		printf("thread create failed!\n");
		return -1;
	}
	printf("main thread is ended!\n tid = %d,pid = %d\n",tidp,getpid());
	pthread_join(tidp,NULL);	//设置阻塞状态，否则主线程会退出
	return 0;
}


