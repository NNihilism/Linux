#include "main.h"

int main(){
	int choice;
	char fileName[30] = {0};

	while(1){

		showMenu();
		printf("输入菜单选项：");
		
		scanf("%d",&choice);
		while(( getchar())!='\n');
		
		switch(choice){
		case 0:	
			return 0;
		case 1: 
			printf("输入要创建的文件名：");
			scanf("%s",fileName);	
			getchar();						//windows系统下也可用fflush()
			//fgets(fileName, 20, stdin);	//会接受空格、制表符Tab和回车等
			createFile(fileName);
			break;
		case 2:
			printf("输入要写入的文件名：");
			scanf("%s",fileName);
			getchar();						
			writeFile(fileName);
			break;
		case 3:
			printf("输入要查看的文件名：");
			scanf("%s",fileName);
			getchar();					
			readFile(fileName);
			break;
		case 4:
			printf("输入要修改的文件名：");
			scanf("%s",fileName);
			getchar();					
			changeRight(fileName);
			break;
		case 5:
			printf("输入要查看的文件名：");
			scanf("%s",fileName);
			getchar();	
			readRight(fileName);
			break;
		}
	}

	return 0;
}


//	C和C++的标准里没有定义过 fflush(stdin)
//	MSDN 文档里内表明
//  fflush on input stream is an extension to the C standard



