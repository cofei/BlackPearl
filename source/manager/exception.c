/*
 * exception.c
 *
 *  Created on: Dec 20, 2019
 *      Author: Markus Kang
 */


#include "../../include/exception.h"

int
ex_handle(jmp_buf jmpbuf)
{
	int jmpret;
	jmpret = setjmp(jmpbuf);

	return jmpret;
}

int
ex_print(int errno)
{
	printf("Error No. is %d\n", errno);
	longjmp(JMPBUF, errno);
	return errno;
}


// Example 1

void ex_sample1()
{
	jmp_buf env;
	int i;
	i = setjmp(env);

	printf("i = %d\n", i);
	if (i != 0)
	{
		exit(0);
	}

	longjmp(env, 2);

	printf("Does this line get printed?\n");

}

