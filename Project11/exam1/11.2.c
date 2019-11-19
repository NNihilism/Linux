/*

	父进程先结束，子进程变成孤儿进程，父进程pid变为1
*/

#include "my.h"
int main()
{
	int pid;
	if((pid = fork())<0)
	{
		perror("fail to fork@\n");
		return -1;
	}
	else if(pid == 0)
	{
		printf("%d child exit now!\n",getpid());
		while(1);
		printf("%d : child is exit now!\n",getpid());
		exit(0);
	}
	else
	{
			printf("%d parent is waitting zombie now\n",getpid());
			while(1);
			printf("%d : parent is exitting now\n",getpid());
		//	while(1);
	}
	exit(0);
}


