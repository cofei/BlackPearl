/*
 * main.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Markus Kang
 */

#include <stdio.h>

#include "include/exception.h"


int main() {
   //printf("Hello World!\n");

   if(ex_handle(JMPBUF, 0, 0))
   {
	   printf("Back in main()\n");
   }
   else
   {
	   printf("First time through\n");
	   ex_case1();
   }

   return 0;
}
