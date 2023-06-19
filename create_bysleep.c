#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//code问题：子线程还没开始执行 主线程就结束了-》空间被释放了
//主线程默认存在 创建子线程后原来的进程退化为主线程

//方法：让主线程sleep 好让子线程运行！
void* callback(void* arg){
    for (int i = 0; i < 5; ++i)
    {
        printf("subthread:i=%d\n",i);
    }
    printf("subthread: %ld\n",pthread_self()); //long int type, current thread id
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
   sleep(3);
   return 0;
}
