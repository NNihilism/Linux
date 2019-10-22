#include "dylib.h"
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#define len 100

int main()
{
	int arr[len],s,m;

	void *hd;
	char *error;
	void (*f1)();
	void (*f2)();
	int (*f3)(),(*f4)();

	hd = dlopen("../libtest.so",RTLD_LAZY);
	if(!hd){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}

	f1 = dlsym(hd,"show");
	if((error = dlerror()) != NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}

	f2 = dlsym(hd,"init");
	if((error = dlerror()) != NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}

	f3 = dlsym(hd,"min");
	if((error = dlerror()) != NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}

	f4 = dlsym(hd,"sum");
	if((error = dlerror()) != NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f2(arr,len);
	f1(arr,len);
	s = f4(arr,len);
	m = f3(arr,len);
	printf("min:%d\t sum:%d\n",m,s);
	
	return 0;
}
