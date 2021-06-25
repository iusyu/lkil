#### Goal

[lab0](https://hackmd.io/@sysprog/linux2021-lab0) details



C programming language

Variadic Function
>可变参数函数，和平常我们使用的函数定义并非一样。如同你在printf函数中所见，这个函数是不定义，想必你肯定为此很好奇。
在c中，这个个实现需要#include <stdarg.h>里面的宏定义。

```c
#include <stdarg.h>
int print_arg(int a, ...)
{
    va_list ap;
    int i = va_arg(ap, int); //每次取一个
    printf("%d",i);
}
```

//如上可以带出两个问题：
怎么才能确定va_list中的arg的个数？
如果我们想回去访问已经取出的arg怎么办?
穿进去的参数如何确定类型？

//如何才能实现一个printf



Signal
信号处理最常见的用法就是Ctr+c向程序发送SIGINT信号。然后程序就会正常释放资源并退出。
但是第二条


