#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <sys/types.h>
#include    <fcntl.h>
#include 	<string.h>

int count = 0;
int main()
{
	pid_t p1,p2,p3;
	p1 = fork();
	int s1,s2,s3,r1,r2,r3;
	if(p1<0)
	{
		perror("fork1 failed.\n");
		return -1;
	}
	else if(p1 == 0)
	{
		count++;
		printf("child pid = %d,ppid = %d,count = %d\n",getpid(),getppid(),count);
		exit(99);
	}
	else
	{
		printf("parent fork second time.\n");
		p2 = fork();
		if(p2 < 0)
		{
			perror("fork2 failed!\n");
			return -1;		
		}
		else if(p2 == 0)
		{
			count++;
			printf("child pid = %d,ppid = %d,count = %d",getpid(),getppid(),count);
			exit(34);
		}
		else
		{
			printf("parent fork third time.\n");
			p3 = fork();
			if(p3 < 0)
			{
				perror("fork3 failed!\n");
				return -1;
			}
			else if(p3 == 0)
			{
				count++;
				printf("child pid = %d,ppid = %d,count = %d",getpid(),getppid(),count);
				exit(99);
			}
			else
			{
				printf("parent waiting!\n");
				r1 = wait(&s1);
				r2 = wait(&s2);
				r3 = wait(&s3);
			}
		}

	}
	
}
