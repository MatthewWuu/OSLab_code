#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//simillar as it is in the create_bysleep.c, this file apply the pthread_exit, which exiting the 
//main thread w/o let go of the stack space

void* callback(void* arg){
    for (int i = 0; i < 10; ++i)
    {
        printf("sub thread:%d\n",i);
    }
    printf("sub thread id:%ld\n",pthread_self());

    return NULL;
}

int main(){
    pthread_t tid; // create a sub thread
    pthread_create(&tid, NULL, callback, NULL);
    for (int i = 0; i < 10; ++i)
    {
        printf("main thread:%d\n",i);
    }
    printf("main thread id:%ld",pthread_self());
    pthread_exit(NULL); //exit the thread without releasing the stack space

    return 0;
}