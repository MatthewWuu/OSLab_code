#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>

// the problem is that the 

#define MAX 50
// ȫ�ֱ���
int number;

// �̴߳�����
void* funcA_num(void* arg)
{
    for(int i=0; i<MAX; ++i)
    {
        //��ֵ��cur�ٸ�numerb��1
        int cur = number;
        cur++;
        //usleep(10);
        number = cur;
        printf("Thread A, id = %ld, number = %d\n",pthread_self(), number);
    }

    return NULL;
}

void* funcB_num(void* arg)
{
    for(int i=0; i<MAX; ++i)
    {
        int cur = number;
        cur++;
        number = cur;
        printf("Thread B, id = %ld, number = %d\n",pthread_self(), number);
        //usleep(5);
    }

    return NULL;
}

int main(int argc, const char* argv[])
{
    pthread_t p1, p2;

    // �����������߳�
    pthread_create(&p1, NULL, funcA_num, NULL);
    pthread_create(&p2, NULL, funcB_num, NULL);

    // ��������Դ����
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    return 0;
}
