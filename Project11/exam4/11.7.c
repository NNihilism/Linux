#include "my.h"

int main()
{
	int pid1,pid2,p1,p2,s1,s2;
	FILE *fp;
	int i;
	fp = fopen("out.dat","w+");
	int num[10] = {1,2,3,4,5,6,7,8,9,10};
	//dup2();
	if(((pid1 = fork()) && (pid2 = fork())) < 0)
	{
		perror("fail to fork");
		return -1;
	}
	if(pid1 == 0)
	{

		for(i = 0;i<10;i++)
		{
			fprintf(fp,"%d",num[i]);
			//sleep(2);
		}
			
		printf("child1:%d succeed to write\n",getpid());
		exit(100);
	}
	if(pid2 == 0)
	{
		for(i = 0;i<10;i++)
		{
			fprintf(fp,"%d",num[i]);
			//sleep(1);
		}

		printf("child2:%d succeed to write\n",getpid());
		exit(200);
	}
	else
	{
		p1 = wait(&s1);
		p2 = wait(&s2);
		if(WEXITSTATUS(&s1) == 100)
		{
			printf("child1 %d\n",p1);
		}
		if(WEXITSTATUS(&s2) == 200)
		{
			printf("child2 %d\n",p2);
		}
	}
}
