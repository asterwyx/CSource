#include"condition.h"

typedef struct Task{           //线程池中的对线需要执行的任务
    void (*run)(void *args);    // 函数指针，需要执行的函数
    void *args;                 // 参数
    struct task *next;          //任务队列中的下一个任务
} Task;


typedef struct ThreadPool{   // 线程池结构体
    Condition ready;         // 状态量（多个线程抢夺一个任务，要保证只有一个线程夺得）对任务，idle,counter进行操作时都要加锁。   
    Task *first;             // 任务队列中第一个任务
    Task *last;              // 任务队列中最后一个任务
    int counter;             // 线程池中已有线程数量
    int idle;                // 线程池中空闲线程数
    int max_threads;         // 线程池最大线程数
    int quit;                // 是否关闭线程池，0不关闭，1关闭
} ThreadPool;

void threadpool_init(ThreadPool *pool, int threads);

void threadpool_add_task(ThreadPool *pool, int threads);

void threadpool_destroy(ThreadPool *pool);
