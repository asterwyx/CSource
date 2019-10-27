#include"threadpool.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>


void *thread_routine(void *arg)
{
    struct timespec abstime;
    int timeout;
    ThreadPool *pool = (ThreadPool *)arg;
    printf("thread %d is starting           poolsize:%d\n", (int)pthread_self(), pool->max_threads);
    while (1)
    {
        timeout = 0;
        condition_lock(&pool->ready);
        pool->idle++;
        while (pool->first == NULL && !pool->quit)
        {
            printf("thread %d is waiting        poolsize:%d\n", (int)pthread_self(), pool->max_threads);
            
        }
    }
    
}