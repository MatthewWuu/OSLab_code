#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//code���⣺���̻߳�û��ʼִ�� ���߳̾ͽ�����-���ռ䱻�ͷ���
//���߳�Ĭ�ϴ��� �������̺߳�ԭ���Ľ����˻�Ϊ���߳�

//�����������߳�sleep �������߳����У�
void* callback(void* arg){
    for (int i = 0; i < 5; ++i)
    {
        printf("subthread:i=%d\n",i);
    }
    printf("subthread: %ld\n",pthread_self()); //long int type, current thread id
    return NULL;
}

int main(){
    pthread_t tid;  //�߳�id
    pthread_create(&tid, NULL, callback, NULL); //�������߳� ԭ�����˻�Ϊ���߳�
    for (int i = 0; i < 5; ++i)
    {
        printf("���߳�:i=%d\n",i);
    }
    printf("���߳� %ld\n",pthread_self()); //long int type, current thread id
   sleep(3);
   return 0;
}
