//���ù�pthread_exit()�˳����߳�ʱ�����лش��Ĳ�����
//������int pthread_join(pthread_t thread, void **tretval)�����ܲ���pthread_exit�����Ĳ��� �������ں���Դ�����߳�
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
            // �ú����Ĳ����������ַ���ݸ������̵߳�pthread_join()
            pthread_exit(&p); //iû��9���˳���
        }
    }
    return NULL;	// ����ִ�в������λ�þ��˳���
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
