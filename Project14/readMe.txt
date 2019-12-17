
1.pthread_create
函数简介
　　pthread_create是UNIX环境创建线程函数

头文件

　　#include<pthread.h>

函数声明

　　int pthread_create(pthread_t  *restrict tidp, const  pthread_attr_t  *restrict_attr,   void*（*start_rtn)(void*),   void   *restrict   arg);

返回值

　　若成功则返回0，否则返回出错编号

参数

　　第一个参数为指向线程标识符的指针。

　　第二个参数用来设置线程属性。

　　第三个参数是线程运行函数的地址。

　　最后一个参数是运行函数的参数。

注意

　　在编译时注意加上-lpthread参数，以调用静态链接库。因为pthread并非Linux系统的默认库

2.void pthread_exit( void * value_ptr );
线程的终止可以是调用了pthread_exit或者该线程的例程结束。也就是说，一个线程可以隐式的退出，也可以显式的调用pthread_exit函数来退出。
pthread_exit函数唯一的参数value_ptr是函数的返回代码，只要pthread_join中的第二个参数value_ptr不是NULL，这个值将被传递给value_ptr。

3. pthread_exit传递多个参数
使用结构体将参数封装后，将结构体指针传给线程

4. pthread_exit返回值不可以为执行函数内的局部变量，不然会发生段错误

