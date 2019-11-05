#include <stdio.h>

#include<unistd.h>
int main()
{

	printf("call:pid = %d,ppid = %d",getpid(),getppid());
	system("/home/nnihilism/桌面/Linux/exam1/test");
	printf("after alling");
	return 0;
}
