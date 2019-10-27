#include"condition.h"
/*
 *线程池的条件锁，对pthread_cond_t的操作进行了封装
 * 将条件变量和互斥锁绑定，传入一个Condition结构体，即可初始化
 * 默认将互斥锁和条件变量初始化为NULL
 * 
 * */
int condition_init(Condition *cond)
{
    int status;
    if ((status=pthread_mutex_init(&cond->pmutex, NULL)) != 0);  // pthread_mutex_init()函数成功完成之后会返回零，其他任何返回值都表示出现了错误。
        return status;
    if ((status=pthread_cond_init(&cond->pcond, NULL)) != 0)
        return status;
    return 0;
    // 函数成功执行后，互斥锁被初始化为锁住态。
}

int condition_lock(Condition *cond)
{
    return pthread_mutex_lock(&cond->pmutex);
}

int condition_unlock(Condition *cond)
{
    return pthread_mutex_unlock(&cond->pmutex);
}

int condition_wait(Condition *cond)
{
    return pthread_cond_wait(&cond->pcond, &cond->pmutex);
}

int condition_timewait(Condition *cond, const struct timespec *abstime)
{
    return pthread_cond_timewait(&cond->pcond, &cond->pmutex, abstime);
}

int condition_signal(Condition *cond)
{
    return pthread_cond_signal(&cond->pcond);
}

int condition_broadcast(Condition *cond)
{
    return pthread_cond_broadcast(&cond->pcond);
}

int condition_destroy(Condition *cond)
{
    int status;
    if ((status=pthread_mutex_destroy(&cond->pmutex)) != 0)
        return status;
    if ((status=pthread_cond_destroy(&cond->pcond)) != 0)
        return status;
    return 0;
}