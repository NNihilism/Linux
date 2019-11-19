/*
	获取多个子进程的退出参数
*/

#include "my.h"
int main()
{
	int pid1,pid2,s1,s2,p1,p2;
	if(((pid1 = fork()) && (pid2 = fork())) < 0)
	{
		perror("fail to fork@\n");
		return -1;
	}
	else if(pid1 == 0)
	{
		printf("%d : child is running now!\n",getpid());
		printf("%d : child is exit now!\n",getpid());
		exit(120);
	}
	else if(pid2 == 0)
	{
		printf("%d : child is running now!\n",getpid());
		printf("%d : child is exit now!\n",getpid());
		exit(130);
	}
	else
	{
			sleep(5);
			printf("%d parent is waitting zombie now\n",getpid());
			p1 = wait(&s1);
			p2 = wait(&s2);
			if(WEXITSTATUS(&s1) == 120)
			{
				printf("child1 %d\n",p1);
			}
			if(WEXITSTATUS(&s2) == 130)
			{
				printf("child2 %d\n",p2);
			}
		/*while((p = waitpid(pid1,&s,WNOHANG)) != -1)
			{
				printf("%d : parent is exitting now\n",getpid());
				if(WIFEXITED(s))		//正常退出
					printf("child %d is exiting normally.exit code = %d\n",p,WEXITSTATUS(s));	//解析低八位
				else if(WIFSIGNALED(s))	//因某种信号退出	
				{
					printf("child %d exit by signal no = %d\n",p,WTERMSIG(s));
				}						
				else	//未知形式退出
				{
					printf("Not know!\n");
				}
			}*/
			
	}
	exit(0);
}


