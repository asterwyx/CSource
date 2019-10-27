#include<pthread.h>

typedef struct Condition{
    pthread_mutex_t pmutex;   // 互斥锁
    pthread_cond_t pcond;
} Condition;

int condition_init(Condition *cond);
int condition_lock(Condition *cond);
int condition_unlock(Condition *cond);
int condition_wait(Condition *cond);
int condition_timewait(Condition *cond, const struct timespec *abstime);
int condition_signal(Condition *cond);
int condition_broadcast(Condition *cond);
int condition_destroy(Condition *cond);

/*
 *互斥锁的属性在创建锁的时候指定，在LinuxThreads实现中仅有一个锁类型属性，不同的锁类型在试图对一个已经被锁定的互斥锁加锁时表现不同。当前（glibc2.2.3,linuxthreads0.9）有四个值可供选择：
 *PTHREAD_MUTEX_TIMED_NP，这是缺省值，也就是普通锁。当一个线程加锁以后，其余请求锁的线程将形成一个等待队列，并在解锁后按优先级获得锁。这种锁策略保证了资源分配的公平性。
 *PTHREAD_MUTEX_RECURSIVE_NP，嵌套锁，允许同一个线程对同一个锁成功获得多次，并通过多次unlock解锁。如果是不同线程请求，则在加锁线程解锁时重新竞争。
 *PTHREAD_MUTEX_ERRORCHECK_NP，检错锁，如果同一个线程请求同一个锁，则返回EDEADLK，否则与PTHREAD_MUTEX_TIMED_NP类型动作相同。这样就保证当不允许多次加锁时不会出现最简单情况下的死锁。
 *PTHREAD_MUTEX_ADAPTIVE_NP，适应锁，动作最简单的锁类型，仅等待解锁后重新竞争。
 * 
**/