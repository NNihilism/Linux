#include <stdio.h>

#include<unistd.h>
int main()
{
	int ret;
	char *args[] = {"./test","123","hello","ncu",NULL};
	printf("call:pid = %d,ppid = %d",getpid(),getppid());
	ret = execvp("/home/nnihilism/桌面/Linux/Project9/exam2/test",args);
	//if(execve("/home/nnihilism/桌面/Linux/Project9/exam2/test",args,NULL)<0)
	//	perror("execve wrong\n");
	printf("after call!ret = %d\n",ret);
	return 0;
}
