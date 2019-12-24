/*
 * varargs.c
 *
 *  Created on: Dec 24, 2019
 *      Author: Markus Kang
 */
#include "../../include/varargs.h"

// sample 1
void va_listargs(int numArgs, ...)
{
	va_list		valist;
	int 		i = 0;

	/* initialize valist for num_args number of arguments */
	va_start(valist, numArgs);
	printf("Number of arguments = %d\n", numArgs);

	/* access all the arguments assigned to valist */
	printf("arguments(");
	for (i = 0; i < numArgs; i++) {

	  printf(" %d", va_arg(valist, int));
	}
	printf(")\n");

	va_end(valist);

	/* initialize valist for num_args number of arguments */
	va_start(valist, numArgs);
	/* access all the arguments assigned to valist */
	printf("again arguments(");
	for (i = 0; i < numArgs; i++) {

	  printf(" %d", va_arg(valist, int));
	}
	printf(")\n");

	/* clean memory reserved for valist */
	va_end(valist);
}

// sample 2

int
va_sum(int numArgs,...) {

   va_list valist;
   int		sum = 0;
   int		var = 0;
   int		i = 0;

   /* initialize valist for num_args number of arguments */
   va_start(valist, numArgs);

   printf("Number of arguments = %d\n", numArgs);

   /* access all the arguments assigned to valist */
   printf("Average of (");
   for (i = 0; i < numArgs; i++) {
      var = va_arg(valist, int);
      printf(" %d", var);
      sum += var;
   }

   /* clean memory reserved for valist */
   va_end(valist);

   printf(") = %d\n", sum);

   return sum;
}


