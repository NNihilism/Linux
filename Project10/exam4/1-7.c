#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g = 8;
int main()
{
	int s = 20;
	static int k = 30;
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		return -1;
	}
	else if(pid == 0)
	{
		printf("child pid = %d : \n&g = %16p\n&k = %16p\n&s = %16p\n",getpid(),&g,&k,&s);
		g = 100;
		s = 200;
		k = 300;

		printf("child after g = %d,k = %d,s = %d\n",g,k,s);
		while(g != 400)
			printf("waiting for g == 400, pid = %d\n",getpid());
		_exit(0);
		//return 0;
	}
	else
	{
		g = 400;
		printf("parent pid = %d : \n&g = %16p\n&k = %16p\n&s = %16p\n",getpid(),&g,&k,&s);
		printf("parent after g = %d,k = %d,s = %d\n",g,k,s);
		return 0;
	}
}
