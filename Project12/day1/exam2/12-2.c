#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <sys/types.h>
#include    <fcntl.h>
#include 	<string.h>
int main(){
	pid_t pid1,pid2,pid3;
	int i;
	char write_buf[5];
	//pid_t r;
	int r_num,len;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));

	// 创建管道
	if(pipe(pipefd)<0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	
	// 父进程写管道
	close(pipefd[0]);
	for(i = 0;i<4096;i++)
	{
		sprintf(write_buf, "%d", i);
	//	itoa(i,write_buf,10);
		if((write(pipefd[1],write_buf,5)) != -1)
			printf("parent write %s.\n",buf);
		else
			perror("failed to write");
	}
	close(pipefd[1]);


	if((pid1 = fork()) < 0)
	{
		perror("failed to fork!\n");
		exit(0);
	}
	else
	{
		// 读管道
		close(pipefd[1]);

		while((r_num =  read(pipefd[0],buf,100))>0)
			printf("child read from pipe:%s,total = %d\n",buf,r_num);
		close(pipefd[0]);

		// 写管道
		for(i = 0;i<4096;i++)
		{
			sprintf(write_buf, "%d", i);
			if((write(pipefd[1],write_buf,5)) != -1)
				printf("child : %d write %s.\n",getpid(),buf);
		}
		close(pipefd[1]);
	}
	return 0;
/*
	if(r<0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(r == 0)
	{	
		close(pipefd[1]);
		sleep(5);
		if((r_num =  read(pipefd[0],buf,100))>0)
			printf("child read from pipe:%s,total = %d\n",buf,r_num);
		close(pipefd[0]);
		sleep(5);
		exit(0);
	}
	else{
		close(pipefd[0]);
		//if(write(pipefd[1],"1234567890",10) != -1)
	//	{
	//		printf("parent write ok.\n");
	//	}
	//	fcntl(pipefd[1], F_SETFL, O_NONBLOCK );
		while(write(pipefd[1],"1",1) != -1)
		{
			len++;
			printf("len : %d\n",len);
		}
		close(pipefd[1]);
		return 0;
	}*/
}

