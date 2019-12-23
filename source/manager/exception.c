/*
 * exception.c
 *
 *  Created on: Dec 20, 2019
 *      Author: Markus Kang
 */


#include "../../include/exception.h"

int
ex_handle(jmp_buf jmpbuf, int major, int minor)
{
	int jmpret;
	jmpret = setjmp(jmpbuf);

	return jmpret;
}

int
ex_print(int errno)
{
	printf("Error No. is %d\n", errno);
	return 0;
}


// Example

void ex_case1()
{
	printf("I'm in ex_case1().\n");
	longjmp(JMPBUF, 1);

	printf("You should never see this because I long jumped!\n");
}

