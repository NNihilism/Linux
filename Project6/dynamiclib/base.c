#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MAX 2147483647
void show(int* arr,int n)
{
	int i;
	for(i = 0;i<n;i++)
		printf("%4d",arr[i]);
	return;
}

void init(int* arr,int n)
{
	int i;
	srand((int)time(0));
	
	//creat random num from 1 to 100
	for(i = 0;i<n;i++)
	{
		arr[i] = 1 + (int)(100.0*rand()/(RAND_MAX + 1.0));
	}
}
