#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int shared = 0;
sem_t m;

void *func_thread1(void *arg)
{
    int x;
    sem_wait(&m);
    printf("\nFirst semaphore");
    x = shared;
    x++;
    sleep(1);
    shared = x;
    sem_post(&m);
}

void *func_thread2(void *arg)
{
    int x;
    sem_wait(&m);
    printf("\nSecond semaphore");
    x = shared;
    x--;
    sleep(1);
    shared = x;
    sem_post(&m);
}


int main()
{
    sem_init(&m, 0, 1);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, func_thread1, NULL);
    pthread_create(&thread2, NULL, func_thread2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}