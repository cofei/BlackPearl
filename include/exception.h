/*
 * exception.h
 *
 *  Created on: Dec 20, 2019
 *      Author: Markus Kang
 */

#ifndef INCLUDE_EXCEPTION_H_
#define INCLUDE_EXCEPTION_H_

#endif /* INCLUDE_EXCEPTION_H_ */

#include <stdio.h>
#include <setjmp.h>

jmp_buf JMPBUF;

int ex_handle(jmp_buf, int, int);
int ex_print(int);
void ex_case1();

