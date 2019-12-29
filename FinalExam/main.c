#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>

#include <pthread.h>

#include <time.h>

#include <semaphore.h>


#define THREAD_NUM 3

//#define LOOP 100

FILE *fp = NULL;									// 文件描述符

int c = 100;									// 控制写操作次数

sem_t sem;											// 信号量

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;	// 互斥锁

void* worker1(void*);

void* worker2(void*);

void* worker3(void*);

void writeCurrentTime();							// 写当前时间

int createRandomNum(int min,int max);				// 生成指定范围的随机数

void main()

{

        int i;

		sem_init(&sem,0,0);						// 信号量初始化

		fp = fopen("mydata.txt","a+");			// append...

		srand((int)time(0));					// seed

        pthread_t tid[THREAD_NUM];			

        pthread_create(&tid[0], NULL, worker1, NULL);
 
        pthread_create(&tid[1], NULL, worker2, NULL);

        pthread_create(&tid[2], NULL, worker3, NULL);


        for(i = 0; i < THREAD_NUM; i++){
                pthread_join(tid[i],NULL);
        }

}




void* worker1(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(c > 0)
		{
			usleep(1000);
		    fprintf(fp,"worker1 : %d\ttime : ",createRandomNum(1,1000));
			writeCurrentTime();
			c--;
			pthread_mutex_unlock(&mutex);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
			sem_post(&sem);		// V操作
			break;
		}
		pthread_yield();
	}
	return NULL;
}


void* worker2(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(c > 0)
		{
			usleep(1000);
		    fprintf(fp,"worker2 : %d\ttime : ",createRandomNum(10000,20000));
			writeCurrentTime();
			c--;
			pthread_mutex_unlock(&mutex);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
			sem_post(&sem);		// V操作
			break;
		}
		pthread_yield();
	}
	return NULL;
}


void* worker3(void* arg)
{
	char line[1024];
	sem_wait(&sem);				// P操作
	fprintf(stderr,"get sem\n");
	fclose(fp);										// 重新定位文件指针应该也行 不试了
	if((fp = fopen("mydata.txt","r")) == NULL)
	{
		fprintf(stderr,"failed to open!");
	}

	while((fgets(line,1024,fp))!=NULL)  
    {  
        fprintf(stderr,line);  		// 输出信息到屏幕
    }  
}


int createRandomNum(int min,int max)
{
	return rand()%(max-min+1)+min;
}


/*
	 输出当前时间到文件中 
	 没有入口参数 偷懒使用全局变量
*/
void writeCurrentTime()
{
	time_t rawtime; 
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	int year,month,day,hour,min,sec;
	year=1900+timeinfo->tm_year;
	month=1+timeinfo->tm_mon;day=timeinfo->tm_mday;
	hour=timeinfo->tm_hour;
	min=timeinfo->tm_min;sec=timeinfo->tm_sec;
	fprintf(fp,"%4d-%02d-%02d %02d:%02d:%02d\n",year,month,day,hour,min,sec);
}

