#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex g_mutex;//锁的一种，排它锁
void T1()
{
    g_mutex.lock();
    cout << "T1 HELLO" << endl;     //输入输出是一种共享资源，共享资源都需要加锁
    g_mutex.unlock();
}

//有参数的函数
void T2(const char* str)
{
    g_mutex.lock();
    cout << "T2" << str << endl;
    g_mutex.unlock();
}

int main()
{
    thread t1(T1);
    thread t2(T2, "Hi");
    t1.join(); 
    t2.join();
    cout << "Hi" << endl;   //主线程这里不用加锁，因为这里已经保证了前面两个已经执行完成的情况下再执行这个，没有人和它竞争
    return 0;
}

/*
T1 HELLOT2Hi

Hi

输出有点奇怪，T1中的换行还没有打印完就。。
如何解决：加锁，保证某条语句是一个原语。看起来一句话，但是hack成汇编语言能发现其有好几句话

*/
