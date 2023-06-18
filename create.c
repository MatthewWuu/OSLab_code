#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//code问题：子线程还没开始执行 主线程就结束了-》空间被释放了
//主线程默认存在 创建子线程后原来的进程退化为主线程

//pthread_t pthread_self(void) 返回当前线程的线程id
//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *),void *arg)
//*thread 创建成功后会把ID指针指向的内存； 属性默认为NULL； 函数指针指向要执行的任务； 实参
//void * 泛型 可以定义结构体 传入结构体的地址
//函数在动态库里 lpthread

void* callback(void* arg){
    for (int i = 0; i < 5; ++i)
    {
        printf("subthread:i=%d\n",i);
    }
    printf("subthread：%ld\n",pthread_self()); //long int type, current thread id
    return NULL;
}

int main(){
    pthread_t tid;  //线程id
    pthread_create(&tid, NULL, callback, NULL); //创建子线程 原进程退化为主线程
    for (int i = 0; i < 5; ++i)
    {
        printf("主线程:i=%d\n",i);
    }
    printf("主线程 %ld\n",pthread_self()); //long int type, current thread id
    return 0;
}
