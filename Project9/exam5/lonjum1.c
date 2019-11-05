#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf g_stack_env;
static void func1(void);
static void func2(void);

int main(void)
{
	if(0 == setjmp(g_stack_env)){
		printf("normal flow\n");
		func1();
	}else{
		printf("Long jump flow\n");
	}
	return 0;
}
static void func1()
{
	printf("Enter func1\n");
	func2();
}

static void func2()
{
	printf("Enter func2\n");
	longjmp(g_stack_env,1);
	printf("Leave func2\n");
}
