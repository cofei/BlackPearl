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


int	ex_handle(jmp_buf, int);
int ex_print(int);


jmp_buf jmpBuf;
