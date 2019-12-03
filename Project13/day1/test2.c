#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>
#include<string.h>
#include<errno.h>
#define PROMPT "Do you want to terminate program?\n"
char* prompt = PROMPT;
void ctrl_c(int signo)
{
	fprintf(stderr,prompt);
}

int main(void)
{
	struct sigaction act;
	act.sa_handler=ctrl_c;
	act.sa_flags=0;
	sigemptyset(&act.sa_mask);
	if(sigaction(SIGINT,&act,NULL)<0)
	{
		fprintf(stderr,"install signal action error : %s\n",strerror(errno));
		exit(1);
	}
	printf("process pid %d\n",getpid());
	while(1);
}
