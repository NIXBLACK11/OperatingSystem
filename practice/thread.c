#include<stdio.h>
#include<pthread.h>
void *funcThread(void *arg)
{
    printf("Inside thread\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d,", i);
    }
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, funcThread, NULL);
    pthread_join(thread, NULL);

    printf("Inside main thread\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d,", i);
    }
}