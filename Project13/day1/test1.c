#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>
#include<string.h>
#include<errno.h>
void sigtoutine(int dunno)
{
	switch(dunno)
	{
		case 1:
		printf("Get a signal SIGHUP\n");
		break;
		case 2:
		printf("Get a signal SIGINT\n");
		break;
		case 3:
		printf("Get a signal SIGQUIT\n");
		break;
	}
}

int main(void)
{
	printf("process pid %d\n",getpid());
	signal(SIGHUP,sigtoutine);
	signal(SIGINT,sigtoutine);
	signal(SIGQUIT,sigtoutine);
	while(1);
}
