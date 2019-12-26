/*
 * main.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Markus Kang
 */

#include <stdio.h>

#include "include/exception.h"
#include "include/varargs.h"
#include "include/multithreads.h"

int main() {


	printf("start mt_sample2()\n");
	mt_sample2();
	printf("end mt_sample2()\n");
	return 0;
}
