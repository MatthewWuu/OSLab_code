//���ù�pthread_exit()�˳����߳�ʱ�����лش��Ĳ�����
//������int pthread_join(pthread_t thread, void **tretval)�����ܲ���pthread_exit�����Ĳ��� �������ں���Դ�����߳�
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
