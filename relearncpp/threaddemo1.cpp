
#include <iostream>
#include <thread>
using namespace std;
void T1()
{
    cout << "HELLO" << endl;
}

int main()
{   
    thread t1(T1);
    /*cpu调度以线程为基本单位，这里线程启动需要一个入口函数，
    T1就是它的入口函数，这个时刻就产生了两个执行流程,但是实际上能不能并行其实取决于是不是多核*/
    /*
    * 如果就到这儿
    这个程序会报错，原因在于主线程比线程t1早返回，t1还没有处理完。
    */
    t1.join();  //主线程会在这里等待，等待t1执行完其逻辑之后主线程再接着往下执行
    cout << "Hi" << endl;//这里的顺序是一定的
    return 0;
}

