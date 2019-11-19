#include <unistd.h>				/*文件与处理，包含标准输入输出库*/
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
void init_daemon(void)
{
	pid_t child1,child2;
	int i;
	child1 = fork();
	if(child1 > 0)				/*创建子进程，终止父进程*/
		exit(0);
	else if(child1 < 0)
	{
		perror("创建子进程失败");	/*fork失败，退出*/
		exit(1);
	}
	setsid();					/*在子进程中创建新会话*/
	chdir("/tmp");				/*改变工作目录到/tmp*/
	umask(0);					/*重设文件创建掩码*/
	for(i = 0;i < NOFILE; ++i)	/*关闭文件描述符*/
		close(i);
	return;
}
