//在用过pthread_exit()退出子线程时候，若有回传的参数，
//可以用int pthread_join(pthread_t thread, void **tretval)来接受参数pthread_exit传出的参数 并回收内核资源到主线程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

struct Person
{
    int age;
    int id;
    char name[36];
}; 

void* callback(void* arg){
    for(int i=0; i<9; ++i)
    {
        printf("im the child thread, the ID: %ld\n", pthread_self());
        if(i == 6)
        {
            struct Persion p;
            p.age  =12;
            strcpy(p.name, "tom");
            p.id = 100;
            // 该函数的参数将这个地址传递给了主线程的pthread_join()
            pthread_exit(&p); //i没到9就退出了
        }
    }
    return NULL;	// 代码执行不到这个位置就退出了
}


int main(){
    pthread_t p;
    pthread_create(&p,NULL,callback,NULL);
    for (int i = 0; i < 6; ++i)
    {
        /* code */
    }
    pthread_joint();
    struct person pp;

    return 0;
}
