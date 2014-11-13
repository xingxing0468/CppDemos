#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <iostream>
#include <sys/wait.h>
#include "unistd.h"
#include "stdlib.h"
#include "time.h"

pthread_mutex_t mutex;
sem_t semSign;
pthread_cond_t barrier;
int count = 0;
pthread_mutex_t mutex2;
void* thread_1a(void *arg)
{
	int i = 0;
//	pthread_mutex_lock(&mutex);
//	pthread_mutex_unlock(&mutex);	
	sem_wait(&semSign);
	sleep(2);
	sem_getvalue(&semSign, &i);
	std::cout<< "sem value after wait and post: "<< i<< std::endl;
	while(i < 20)
	{
		std::cout<<"thread_1 is running: number["<<i<<"]"<<std::endl;
		sleep(1);
		i++;
	}
}

void* thread_2a(void *arg)
{
	int i = 0;
//	pthread_mutex_lock(&mutex);
//	int semValue = 0;
//	sem_getvalue(&semSign, &semValue);
//	std::cout << "[thread] [2] semvalue init: " << semValue << std::endl;
//	sem_wait(&semSign);
//	sem_getvalue(&semSign, &semValue);
//	std::cout << "[thread] [2] semvalue after 1 time wait: " << semValue << std::endl;
	
	pthread_mutex_lock(&mutex);
	while(i < 5)
	{
		count ++;
		std::cout<<"[Thread] [2] is adding the count: count["<<count<<"]"<<std::endl;
		sleep(1);
		i++;
	}
	
	i = 0;
	pthread_mutex_unlock(&mutex);
	
	std::cout <<"[Thread 2] is blocked by the barrier!" << std::endl;
	pthread_cond_wait(&barrier,&mutex);
	pthread_mutex_unlock(&mutex);
	while(i < 5)
	{
		std::cout<<"[Thread 2] has been broadcasted and is running: number["<<i<<"]"<<std::endl;
		sleep(1);
		i++;
	}
	i = 0;
	//pthread_mutex_unlock(&mutex);
}

void* thread_3a(void *arg)
{
//	int i = 0;
//	pthread_mutex_lock(&mutex);
//	timespec ts;
//	clock_gettime(CLOCK_REALTIME, &ts);
//	ts.tv_sec += 5;
//	int semValue = 0;
	//sem_getvalue(&semSign, &semValue);
//	std::cout << "[Thread] [3] semSign Value: " << semValue << std::endl; 
//	std::cout << "timed wait value: "<< sem_timedwait(&semSign, &ts)<<std::endl;
//	sem_getvalue(&semSign, &semValue);
//	std::cout << "[Thread] [3] semSign Value after 1 timed wait: " << semValue << std::endl;
	//sem_post(&semSign);
	//sem_getvalue(&semSign, &semValue);
	//std::cout << "semSign after 1 time post: "<< semValue  << std::endl;
//	std::cout << "timed wait value after 1 time post: "<< sem_timedwait(&semSign, &ts)<<std::endl;
//	sem_getvalue(&semSign, &semValue);
//	std::cout << "[Thread] [3] semSign Value after 2 timed wait: " << semValue << std::endl;
///	pthread_mutex_lock(&mutex);
//	while(i < 5)
//	{
//		std::cout<<"thread_3 is running: number["<<i<<"]"<<std::endl;
//		sleep(1);
//		i++;
//	}
//pthread_mutex_unlock(&mutex);
//	sem_post(&semSign);
//	sem_getvalue(&semSign, &semValue);
//	std::cout << "semSign Value after 2 time post: " << semValue << std::endl;
//	pthread_mutex_unlock(&mutex);
	


 	int i = 0;
	pthread_mutex_lock(&mutex);
	while(i < 5)
	{
		count ++;
		std::cout<<"[Thread] [3] is adding the count: count["<<count<<"]"<<std::endl;
		sleep(1);
		i++;
	}
	i = 0;
	pthread_mutex_unlock(&mutex);
	
	std::cout << "Thread: [Thread 3] is blocked by the barrier!" << std::endl;
	pthread_cond_wait(&barrier,&mutex);
	pthread_mutex_unlock(&mutex);
	while(i < 5)
	{
		std::cout<<"[Thread 3] has been broadcasted and is running: number["<<i<<"]"<<std::endl;
		sleep(1);
		i++;
	}
	i = 0;
	//pthread_mutex_unlock(&mutex);
}

int main()
{
	int err;
	void* status;
	pthread_t threadId1;
	pthread_t threadId2;
	pthread_t threadId3;
	pthread_t threadId4;
	pthread_cond_init(&barrier,NULL);
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&mutex2, NULL);
	sem_init(&semSign, 0, -1); 
	err = pthread_create(&threadId1, NULL, thread_1a,  NULL);
	//err = pthread_create(&threadId2, NULL, thread_2a,  NULL);
	//err = pthread_create(&threadId3, NULL, thread_3a,  NULL);
	//err = pthread_create(&threadId2, NULL, thread_2a,  NULL);
	int j = 0;
	sem_getvalue(&semSign, &j);
	std::cout << "semvalue : " << j << std::endl; 
	sem_post(&semSign);
	sem_getvalue(&semSign, &j);
	std::cout << "semValue after post:" << j << std::endl;
	while (1)
	{
		j++;
		std::cout <<"[Main Thread] is Waiting, j = " << j << std::endl;
		sleep(1);
		if(count >= 9) {
		sleep(3);
		break;	}
	}
	//pthread_mutex_lock(&mutex);
	std::cout <<"[Main Thread] has reached, broadcast to release all the barriers" << std::endl;
	pthread_cond_broadcast(&barrier);
	//pthread_mutex_unlock(&mutex);
	//pthread_mutex_unlock(&mutex2);
	//pthread_join(threadId1,&status);
	pthread_join(threadId2,&status);
	pthread_join(threadId3,&status);
	//std::cout << "barrier has been signaled! and wait for 5 senconds!" << std::endl;
	pthread_cond_destroy(&barrier);
	pthread_mutex_destroy(&mutex);
	sem_destroy(&semSign);
	return 0;
}
