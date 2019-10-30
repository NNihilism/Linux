#include "main.h"

/*

	功能：菜单显示

	入口参数：无

	返回值：无
*/
void showMenu_1(){
	printf("***************************\n");
	printf("0.退出\n");
	printf("1.创建新文件\n");
	printf("2.写文件\n");
	printf("3.读文件\n");
	printf("4.修改文件权限\n");
	printf("5.查看当前文件的权限\n");
	printf("***************************\n");
}


/*

	功能：新建文件		

	入口参数：char* fileName文件名

	返回值：无

*/
void createFile_1(char* fileName){

	FILE* fp;
	int choice;
	
	if ( (fp = fopen(fileName, "r")) != NULL )	//r  ----  以只读形式打开文件，若文件不存在，则返回NULL 
	{
        printf("创建失败，文件已存在。是否覆盖原文件？<Y|N>");

        while((choice = getchar())!= 'Y' && choice != 'N');//只允许用户输入Y|N

		if(choice == 'N')
			return;
		else if(choice == 'Y')
		{
			if ((fp = fopen(fileName, "w+")) == NULL)	//w+ ---- 以读写的形式打开文件，若文件不存在，则创建文件。若文件存在，则清空原文件内容
				puts("创建失败");
			else
				puts("创建成功");
		}
    }else
	{
		if((fp = fopen(fileName,"w+")) != NULL)
			puts("创建成功!");
	}

	fclose(fp);

/*	open属于linux的系统调用  fopen属于标准C

	int fd=open(fileName,O_WRONLY | O_CREAT | O_TRUNC,0600);
    
    if(fd == -1)
    {
       printf("创建失败！\n");
    }
    else
    {
       printf("创建成功！\n");
    }
	close(fd);
*/
}

/*

	功能：往指定文件内写入数据

	入口参数：char* fileName文件名

	返回值：无

*/
void writeFile_1(char* fileName){
	FILE* fp;
	char buffer[50] = {0};	//用户每行输入的内容

	if((fp = fopen(fileName,"a+")) == NULL)		
	{
		perror("打开文件失败");
	}

	puts("输入-quit即可退出");
	fgets(buffer, 50, stdin);
	while(strncmp(buffer,"-quit",5)){
		fwrite (buffer , sizeof(char), strlen(buffer) , fp );	//注：strlen(buffer)与sizeof(buffer)的区别
		//buffer = {0};//可以想下为什么不用重新将数组初始化   为什么不担心将上一次用户输入的内容重复写入文件	
		fgets(buffer, 50, stdin);
	};
	puts("完成写入");
	fclose(fp);
}




/*

	功能：读取指定文件的内容

	入口参数：char* fileName文件名

	返回值：无

*/
void readFile_1(char* fileName){
	FILE* fp;
	char buffer[50] = {0};

	if ( (fp = fopen(fileName, "r")) == NULL )
	{
		perror("文件不存在");	
		return;
	}


	while(!feof(fp))
	{
		fgets(buffer,sizeof(buffer),fp);
		printf("%s",buffer);
	}

	fclose(fp);
}


/*

	功能：修改文件权限信息

	入口参数：char* fileName文件名

	返回值：无

*/
void changeRight_1(char* fileName){

    int mode;
    int mode_u;//所有者权限
    int mode_g;//所属组权限
    int mode_o;//其他人权限d
	char s_mode[3];

	printf("输入修改后的权限，如777:");
	scanf("%s",s_mode);

    mode=(atoi(s_mode));//将要设置的权限字符串转换成整数,如"777"转换成777

    if(mode>777||mode<0){//验证要设置的权限是否合法
        printf("Error mode!\n"); 
        return;
    }
 
    mode_u=mode/100; 
    mode_g=mode/10%10;
    mode_o=mode%10;
    mode=mode_u*8*8+mode_g*8+mode_o;//八进制转换

    if(chmod(fileName,mode) ==-1){//调用chmod函数进行权限修改
        perror("Error mode!\n");
        return;
    }
	puts("权限修改成功");


}

/*

	功能：查看文件权限信息

	入口参数：char* fileName文件名

	返回值：无

*/
void readRight_1(char* fileName){
       struct stat fileInfo;

       if (stat(fileName, &fileInfo) < 0)
               exit(0);

       unsigned int mask = 0000777;
       unsigned int access = mask & fileInfo.st_mode;
       printf("%o\n%d\n", access, fileInfo.st_uid);
}
