#include "my.h"
#define BUF_4K 4*1024
#define BUF_8K 8*1024
#define BUF_12K 12*1024

int main(void)
{
	char a[BUF_4K];
	char b[BUF_8K];
	char c[BUF_12K];
	int fd[2];
	int ret = pipe(fd);
	memset(a,'A',sizeof(a));
	memset(b,'B',sizeof(b));
	memset(c,'C',sizeof(c));

	if(ret == -1)
	{
		fprintf(stderr,"create pipe error (%s)\n",strerror(errno));
		exit(-1);
	}

	//---------------------第二次fork
	pid_t pid;
	pid = fork();

	if(pid == -1)
	{
		fprintf(stderr,"first fork error (%s)\n",strerror(errno));
		exit(-2);
	}
	else if(pid == 0)
	{
		close(fd[0]);

		int loop = 0;

		while(loop++<10)
		{
			ret = write(fd[1],a,sizeof(a));
			printf("[child] pid = %d write %d bytes(A) to pipe.\n",getpid(),ret);

		}

		exit(0);
	}

	//---------------------第一次fork
	pid = fork();

	if(pid == -1)
	{
		fprintf(stderr,"second fork error (%s)\n",strerror(errno));
		exit(-3);
	}
	else if(pid == 0)
	{
		close(fd[0]);

		int loop = 0;

		while(loop++<10)
		{
			ret = write(fd[1],b,sizeof(b));
			printf("[child] pid = %d write %d bytes(B) to pipe.\n",getpid(),ret);

		}

		exit(0);
	}

	//---------------------第三次fork
	pid = fork();

	if(pid == -1)
	{
		fprintf(stderr,"third fork error (%s)\n",strerror(errno));
		exit(-4);
	}
	else if(pid == 0)
	{
		close(fd[0]);

		int loop = 0;

		while(loop++<10)
		{
			ret = write(fd[1],c,sizeof(c));
			printf("[child] pid = %d write %d bytes(C) to pipe.\n",getpid(),ret);

		}

		exit(0);
	}

	close(fd[1]);
	sleep(2);
	int file = open("./test.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);	//不存在则创建文件，文件权限为0644可读写
	char buf[1024*4] = {0};
	int n = 1;
	while(1)
	{
		ret = read(fd[0],buf,sizeof(buf));
		if(ret == 0)
			break;
		printf("n = %02d pid = %d read %d bytes from pipe buf[4095] = %c\n",n++,getpid(),ret,buf[4095]);
		write(file,buf,ret);
	}

	return 0;
}
