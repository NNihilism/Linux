#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>
#include<string.h>

int main()
{	
	pid_t pid1=-1,pid2=-1,pid3=-1;
	int pipe_fd1[2],pipe_fd2[2],r_num,i,j;
	int r1,r2,r3,s1,s2,s3;
	int buf_r[4096],sum=0;
	memset(buf_r,0,sizeof(buf_r));
	if((pipe(pipe_fd1))<0)
	{
		perror("创建管道1失败\n");
		return -1;
	}
	if((pipe(pipe_fd2))<0)
	{
		perror("创建管道2失败\n");
		return -1;
	}
	if((pid1=fork())<0)
	{
		perror("创建子进程失败!\n");
		return -1;
	}	
	if(pid1 == 0)
	{
		close(pipe_fd1[0]);
		for(i = 0;i<4096;i++)
		{
			if(write(pipe_fd1[1],&i,sizeof(int)) == -1)
				break;		
			printf("child1: write int: %d\n",i);					
		}				
		close(pipe_fd1[1]);
		exit(0);
	} 		
	else
	{		
		if((pid2=fork())<0)
		{
			perror("创建子进程失败!\n");
			return -1;
		}	
		if(pid2 == 0)
		{
			sleep(3);
			close(pipe_fd1[1]);
			close(pipe_fd2[0]);			
			
			j = 0;
			while(j<4)	
			{
				j++;
				r_num = read(pipe_fd1[0],buf_r,1024*sizeof(int));
				for(i=0;i<r_num/sizeof(int);i++)
				{
					printf("child2 read from pipe1: %d\n",buf_r[i]);
				}					
				if(write(pipe_fd2[1],buf_r,r_num) == -1)
				{
					printf("child2 write pipe2 error\n");
					break;		
				}	
			}						
			close(pipe_fd2[1]);
			close(pipe_fd1[0]);
			exit(0);
		} 	
		else
		{
			if((pid3=fork())<0)
			{
				perror("创建子进程失败!\n");
				return -1;
			}	
			if(pid3 == 0)
			{
				sleep(6);
				close(pipe_fd2[1]);
				j = 0;
				while(j<4)	
				{
					j++;
					r_num = read(pipe_fd2[0],buf_r,1024*sizeof(int));
					printf("child3: read length %d\n",r_num);
					for(i=0;i<r_num/sizeof(int);i++)
					{
						sum+=buf_r[i];
					}
					printf("child3: sum: %d\n",sum);
				}										
				close(pipe_fd2[0]);
				exit(0);
			}
			else
			{
				r1 = wait(&s1);
				r2 = wait(&s2);
				r3 = wait(&s3);
				exit(0);
			}
		}
	}
}
