/*
 * main.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Markus Kang
 */

#include <stdio.h>

#include "include/exception.h"
#include "include/memgr.h"
#include "include/varargs.h"
#include "include/multithreads.h"

int main()
{
	printf("START... main()\n");
	me_case1();
	me_case2();
	me_case3();
	me_case4();

	printf("END... main()\n");
	return 0;
}
