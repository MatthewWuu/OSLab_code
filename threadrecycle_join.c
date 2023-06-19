//在用过pthread_exit()退出子线程时候，若有回传的参数，
//可以用int pthread_join(pthread_t thread, void **tretval)来接受参数pthread_exit传出的参数 并回收内核资源到主线程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

struct person
{
    int age;
    int id;
    char name[36];
}p; //define a struct variable btw

void* callback(){

    return NULL;
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
