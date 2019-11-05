#include <stdio.h>
#include<unistd.h>
int main()
{
	int ret;
	printf("call:pid = %d,ppid = %d",getpid(),getppid());
	ret = system("/home/nnihilism/桌面/Linux/Project9/exam1/test");
	printf("after alling,ret:%d\n",ret);
	return 0;
}
