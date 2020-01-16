/*
 * memgr.h
 *
 *  Created on: Jan 15, 2020
 *      Author: Markus Kang
 */

#ifndef INCLUDE_MEMGR_H_
#define INCLUDE_MEMGR_H_



#endif /* INCLUDE_MEMGR_H_ */

#include <stdio.h>
#include <string.h>

void *memorycopy(const void *src, void *dst, size_t n);
void *memorymove(const void *src, void *dst, size_t n);

#define MEMCOPY(src, dest, n)	(void *) memorycopy((const void *)(src), (void *)(dest), (size_t) n)
#define MEMMOVE(src, dest, n)	(void *) memorymove((const void *)(src), (void *)(dest), (size_t) n)


int me_case1();
int me_case2();
int me_case3();
int me_case4();
