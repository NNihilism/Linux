c中goto这个指令不能跨函数跳跃，而setjump和longjump可以解决这个问题
使用longjmp后，无需一层一层的返回，而是可以直接返回到main函数

gcc longjmp2.c -o longjmp21 -Wall -O2
使用O2优化后局部变量会被压栈
