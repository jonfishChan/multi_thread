#ifndef _DF_THREAD_COMMON_H_
#define _DF_THREAD_COMMON_H_

#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
 
using namespace std;
 
class threadCommon
{
private:
    //获取执行方法的指针
    static void * thread_proxy_func(void * args);
    //内部执行方法
    void* run1();
protected:
    //当前线程的线程ID
    pthread_t tid;
    //线程的状态
    int threadStatus;
public:
    //线程的状态－新建
    static const int THREAD_STATUS_NEW = 0;
    //线程的状态－正在运行
    static const int THREAD_STATUS_RUNNING = 1;
    //线程的状态－运行结束
    static const int THREAD_STATUS_EXIT = -1;
    //构造函数
    threadCommon();
    //析构函数
    ~threadCommon();
    //线程的运行实体
    virtual void run()=0;
    //开始执行线程
    bool start();
    //获取线程ID
    pthread_t getThreadID();
    //获取线程状态
    int getState();
    //等待线程直至退出
    void join();
    //等待线程退出或者超时
    void join(unsigned long millisTime);
};


#endif


