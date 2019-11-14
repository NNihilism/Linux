#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
    pid_t pid;
    int fd1, i = 1;

    fd1 = open("vfork.txt",O_CREAT | O_RDONLY | O_WRONLY | O_APPEND,0755);
    if(fd1 < 0)
    {
        perror("fail to open");
        exit(1);
    }
    dup2(fd1,STDOUT_FILENO);
    pid = vfork();
    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
		while(i<=10)
		{
	    		printf("write %d by child\n",i++);
			sleep(1);
		}

		exit(0);
    }
    else
    {
	i = 1;
        while(i<=10)
	{
		printf("write %d by parent\n",i++);
		sleep(1);
	}
        	
    }

    return 0;
}
