/*

	获取退出参数
*/

#include "my.h"
int main()
{
	int pid,s;
	if((pid = fork())<0)
	{
		perror("fail to fork@\n");
		return -1;
	}
	else if(pid == 0)
	{
		printf("%d child is running now!\n",getpid());
		printf("%d : child is exit now!\n",getpid());
		//while(1);	用于验证信号退出，如kill命令
		exit(120);
	}
	else
	{
			printf("%d parent is waitting zombie now\n",getpid());
			while((pid = wait(&s)) != -1)
			{
				printf("%d : parent is exitting now\n",getpid());
				if(WIFEXITED(s))		//正常退出
					printf("child %d is exiting normally.exit code = %d\n",pid,WEXITSTATUS(s));	//解析低八位
				else if(WIFSIGNALED(s))	//因某种信号退出	
				{
					printf("child %d exit by signal no = %d\n",pid,WTERMSIG(s));
				}						
				else	//未知形式退出
				{
					printf("Not know!\n");
				}
			}

	}
	exit(0);
}


