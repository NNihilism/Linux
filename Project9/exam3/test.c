#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int global1 = 1;
int global2 = 2;

int main()
{
	int i = 10;
	pid_t pid;
	static int k = 20;
	pid = fork();
	if(pid<0)
	{
		perror("fail to create child thread");
		exit;
	}
	else if(pid == 0)
	{
		printf("child pid:%d,ppid = %d\n i:%d, k:%d, global1:%d, global2:%d\n"
				,getpid(),getppid(),i,k,global1,global2);
		i = 20;k = 20;global1 = 3;global2 = 4;
		exit(0);
	}
	else
	{
		printf("child pid:%d,ppid = %d\n i:%d, k:%d, global1:%d, global2:%d\n"
				,getpid(),getppid(),i,k,global1,global2);
		exit(0);
	}
	return 0;
}
