#include "dylib.h"
#include <stdio.h>
#define len 100

int main()
{
	int arr[len],s,m;
	init(arr,len);
	show(arr,len);
	s = sum(arr,len);
	m = min(arr,len);
	printf("min:%d\t sum:%d\n",m,s);
	
	return 0;
}
