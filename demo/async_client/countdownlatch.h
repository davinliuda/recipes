#ifndef _COMMON_COUNTDOWNLATCH_H_
#define _COMMON_COUNTDOWNLATCH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <sys/types.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

class CountDownLatch{
public:
    CountDownLatch(int cnt) : cdl_count_(0){
        int err = pthread_mutex_init(&cdl_mutex_, NULL);
        assert(err == 0);
        sem_init(&cdl_sem_, 0, 0);
        cdl_count_ = cnt;
    }
    
    void set_count(int cnt){
        pthread_mutex_lock(&cdl_mutex_);
        cdl_count_ = cnt;
        pthread_mutex_unlock(&cdl_mutex_);
    }
    
    void countdown(){
        pthread_mutex_lock(&cdl_mutex_);
        cdl_count_ -= 1;
        if(cdl_count_ <= 0)
        {
            sem_post(&cdl_sem_);
        }
        pthread_mutex_unlock(&cdl_mutex_);
    }
        
    int getcount()
    {
        return cdl_count_;
    }

    int wait(){
        return sem_wait(&cdl_sem_);
    }

    int wait(const timeval* timeout)
    {
        if (timeout == NULL)
        {
            return wait();
        }
        timeval t0;
        gettimeofday(&t0, NULL);
        int64_t s  = t0.tv_usec + timeout->tv_usec;
        timespec ts;
        ts.tv_sec  = t0.tv_sec + timeout->tv_sec + s/1000000;
        ts.tv_nsec = s % 1000000 * 1000;
        int ret = 0;
        while(((ret = sem_timedwait(&cdl_sem_, &ts)) != 0 ) && (errno==EINTR));
    }

private:
    int cdl_count_;
    pthread_mutex_t cdl_mutex_;
    sem_t cdl_sem_;
};

#endif

