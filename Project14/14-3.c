#include "my.h"
#define NUM_THREADS 4
struct info{
	int no;
	int n;
};

void* hello(void *t)
{


	float time_use=0;
	struct timeval start;
	struct timeval end;//struct timezone tz; //后面有说明

	pthread_t my_tid;
	struct info *y;
	int s = 0;

	gettimeofday(&start,NULL); //gettimeofday(&start,&tz);结果一样

	y = (struct info *)(t);	
	my_tid = pthread_self();
	for(int i = 0;i<=y->n;i++)
		s+=i;
	printf("\tThread %d: my tid is %lx,Hello world\n",(int)y->no,my_tid);
	printf("\tThread %d: sum 1 to %d is %d\n",(int)y->no,y->n,s);


//	printf("start.tv_sec:%dn",start.tv_sec);
//	printf("start.tv_usec:%dn",start.tv_usec);

//	sleep(3);
	gettimeofday(&end,NULL);
//	printf("end.tv_sec:%dn",end.tv_sec);
//	printf("end.tv_usec:%dn",end.tv_usec);
	time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
	printf("\tThread %d :time_use is %f\n",(int)y->no,time_use);
	pthread_exit((void *)&s);		//返回值
	return NULL;
//return time_use;
}

int main()
{
	pthread_t tid[4];
	struct info a[4];	
	void** rst[4];
	int rv,t;
	for(t = 0;t<NUM_THREADS;t++)
	{
		a[t].no = t;
		a[t].n = 100*(t+1);
		rv = pthread_create(&tid[t],NULL,(void*(*)())hello,(void*)&a[t]);
		if(rv!=0)
		{
			printf("thread create failed\n");
			return -1;
		}	
		printf("create thread tid = %lx\n",tid[t]);
		pthread_join(tid[t],&rst[t]);
		printf("the child%d return: %f\n",a[t].no,(int*)rst[t]);
	}
	/*printf("Good bye!\n");
	pthread_join(tid[0],&rst[0]);
	pthread_join(tid[1],&rst[1]);
	pthread_join(tid[2],&rst[2]);
	pthread_join(tid[3],&rst[3]);
	printf("the child%d return: %f\n",a[0].no,(int*)rst[0]);
	printf("the child%d return: %f\n",a[1].no,(int*)rst[1]);
	printf("the child%d return: %f\n",a[2].no,(int*)rst[2]);
	printf("the child%d return: %f\n",a[3].no,(int*)rst[3]);*/
	//pthread_exit(NULL);	//让主线程等待子线程
	return 0;
	
}
