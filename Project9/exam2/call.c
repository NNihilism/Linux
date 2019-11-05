#include <stdio.h>

#include<unistd.h>
int main()
{
	char *args[] = {"./test",NULL};
	printf("call:pid = %d,ppid = %d",getpid(),getppid());
	if(execve("/home/nnihilism/桌面/Linux/exam2/test",args,NULL)<0)
		perror("execve wrong\n");
	printf("after call\n");
	return 0;
}
