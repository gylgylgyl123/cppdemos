#include <stdio.h>
#include <stdlib.h>

#define _PAUSE() system("pause");
#if (defined DEBUG) || (defined _DEBUG) //检测构建模式是否为调试模式
//如果构建模式为调试模式，这里定义几个宏
#define _DEBUGNOW
#define _PUTSIL(NUM) printf("%d\n",NUM) //输出整数
#define _PUTFD(NUM) printf("%f\n",NUM) //输出浮点数
#else
//如果构建模式为发布模式，自动忽略这些宏的存在
#define _PUTSIL(NUM) ((void)0)
#define _PUTFD(NUM) ((void)0)
#endif

int main() {
#ifdef _DEBUGNOW 
    printf("正在为调试做准备...\n");
#endif // _DEBUGNOW
    printf("程序正在运行...\n");
    _PUTSIL(12666);
    _PUTFD(3.1415926535898);
    printf("程序运行完毕...\n");
    _PAUSE(); // 暂停程序
    return 0;
}
