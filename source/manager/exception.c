/*
 * exception.c
 *
 *  Created on: Dec 20, 2019
 *      Author: Markus Kang
 */


#include "../../include/exception.h"

int
ex_handle(jmp_buf jmpbuf, int errno)
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