/*
 * main.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Markus Kang
 */

#include <stdio.h>

#include "include/exception.h"
#include "include/varargs.h"


int main() {

	va_listargs(3, 1,2,3);
	va_listargs(6, 5,6,7,8,9,10);

   return 0;
}
