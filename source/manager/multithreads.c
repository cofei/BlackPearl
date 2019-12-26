/*
 * MultiThreads.c
 *
 *  Created on: Dec 26, 2019
 *      Author: Markus Kang
 */

#include "../../include/multithreads.h"

void *mt_print(void *threadid);
void *mt_add(void *threadid);

#define NUM_THREADS 4

int MT_START, MT_NOW, MT_END;
long long MT_SUM;

pthread_mutex_t NOW_LOCK;

void *mt_print(void *threadid)
{
	int thdid;
	thdid = (int) threadid;
	printf("Thread #%d: Hello World!\n", thdid);
	pthread_exit(NULL);
}

void *mt_add(void *threadid)
{
	int i = MT_NOW;
	printf("Thread #%d: Hello MT_NOW = %d! \n", (int)threadid, MT_NOW);
	if (MT_NOW > MT_END)
	{
		printf("Thread #%d: BYE MT_NOW = %d!\n", (int)threadid, MT_NOW);
		pthread_exit(NULL);
	}

	i = MT_NOW;
	while (1)
	{
		pthread_mutex_lock(&NOW_LOCK);
		if ((MT_NOW > MT_END)
				|| (i > MT_END))
		{
			pthread_mutex_unlock(&NOW_LOCK);
			break;
		}

		MT_SUM += MT_NOW;
		MT_NOW++;
		i++;

		pthread_mutex_unlock(&NOW_LOCK);

	}

	printf("Thread #%d: BYE MT_NOW = %d!\n", (int)threadid, MT_NOW);
	pthread_exit(NULL);

}



// Example 1
void mt_sample1()
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long i;

	for (i = 0; i < NUM_THREADS; i ++)
	{
		printf("main(); creating thread, #%ld\n", i);
		rc = pthread_create(&threads[i], NULL, mt_print, (void *)i);
		if (rc)
		{
			printf("Error:unable to create thread, #%d\n", rc);
			exit(-1);
		}
	}

	pthread_exit(NULL);
}


// Example 2
void mt_sample2()
{
	pthread_t threads[NUM_THREADS];
	int i = 0;
	int rc = 0;

	MT_SUM = 0;
	MT_NOW = 1;
	MT_END = 1000000;

	pthread_mutex_init (&NOW_LOCK,NULL);

	for (i = 0; i < NUM_THREADS; i ++)
	{
		printf("Thread #%d: creating...\n", i);
		rc = pthread_create(&threads[i], NULL, (void *)&mt_add, (void *)i);
		if (rc)
		{
			printf("Thread #%d: Error:unable to create.\n", rc);
			exit(-1);
		}
	}

	for (i = 0; i < NUM_THREADS; i ++)
	{
		printf("Thread #%d: Waiting...\n", i);
		pthread_join(threads[i], NULL);
	}


	printf("sum = %lld\n",MT_SUM);

}
