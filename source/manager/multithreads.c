/*
 * MultiThreads.c
 *
 *  Created on: Dec 26, 2019
 *      Author: Markus Kang
 */

#include "../../include/multithreads.h"

void *mt_print(void *threadid);
void *mt_add(void *threadid);
void *mt_display(int isEnd);

#define NUM_THREADS		4
#define STR_LENGTH		20

char *STR_BUF, *STR_START, *STR_END;
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
	while (MT_NOW <= MT_END)
	{
		pthread_mutex_lock(&NOW_LOCK);
		if ((MT_NOW > MT_END))
		{
			pthread_mutex_unlock(&NOW_LOCK);
			break;
		}

		MT_SUM += MT_NOW;
		MT_NOW++;

		pthread_mutex_unlock(&NOW_LOCK);
	}

	printf("Thread #%d: BYE MT_NOW = %d!\n", (int)threadid, MT_NOW);
	pthread_exit(NULL);
}

void *mt_display(int isEnd)
{
	int		str_len = strlen(STR_BUF);

	STR_START = STR_BUF;
	STR_END = STR_BUF+(str_len -1);

	while (!isEnd)
	{
		STR_START = STR_BUF;
		STR_END = STR_BUF+(str_len -1);

		if (str_len >= STR_LENGTH)
		{
			//pthread_mutex_lock(&NOW_LOCK);
			printf("%s\n", STR_START);
			//pthread_mutex_unlock(&NOW_LOCK);
		}
		else
		{
			continue;
		}
	}

	if (isEnd)
	{
		//pthread_mutex_lock(&NOW_LOCK);
		printf("%s\n", STR_START);
		//pthread_mutex_unlock(&NOW_LOCK);
	}

	printf("Thread # BYE!\n");
	//pthread_exit(NULL);

	return NULL;
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

// Example 3
void mt_sample3()
{
	//pthread_t	thread_id;
	//int			rc;

	STR_BUF = (char *)malloc(sizeof(char)* (STR_LENGTH + 1));
	(void) memset((void*)(STR_BUF), 0, (STR_LENGTH + 1));

	/*
	pthread_mutex_init (&NOW_LOCK,NULL);

	printf("Thread #0: creating...\n");
	rc = pthread_create(&thread_id, NULL, (void *)&mt_display, NULL);
	if (rc)
	{
		printf("Thread #: Error:unable to create.\n", rc);
		exit(-1);
	}
	*/

	sprintf(STR_BUF, "%s", "TEST CASE 3 AAAAAAAAAAAAAAAAAAAAAA");
	mt_display(1);

	/*
	printf("Thread #0: Waiting...\n");
	pthread_join(thread_id, NULL);
	*/


}
