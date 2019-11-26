#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <sys/types.h>
#include    <fcntl.h>
#include 	<string.h>
int main(){

	pid_t r;
	int r_num,len;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	r = fork();
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
		while(write(pipefd[1],"1",1) != -1)
		{
			len++;
			printf("len : %d\n",len);
		}
		close(pipefd[1]);
		return 0;
	}
}

