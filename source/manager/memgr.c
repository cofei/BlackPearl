/*
 * memgr.c
 *
 *  Created on: Jan 15, 2020
 *      Author: Markus Kang
 */

#include "../../include/memgr.h"

void *memorycopy(const void *src, void *dst, size_t n)
{
	char *td = (char *)dst;
	char *ts = (char *)src;

	while (n--)
	{
		*td++ = *ts++;
	}
	return dst;
}

void *memorymove(const void *src, void *dst, size_t n)
{
	char *td = (char *)dst;
	char *ts = (char *)src;

	if ((td > ts) && (td < (ts + n)))
	{
		td = td + (n - 1);
		ts = ts + (n - 1);
		while(n--)
		{
			*td-- = *ts--;
		}
	}
	else
	{
		while (n--)
		{
			*td++ = *ts++;
		}
	}
	return dst;
}


// test case

int me_case1()
{
	int		n = 5;
	char	str[20] = "abcde\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
	char	*src;
	char	*dst;

	src = &str[0];
	dst = &str[2];

	MEMMOVE(src, dst, n);

	printf("src = %s\n", src);
	printf("dst = %s\n", dst);

	return 0;
}

int me_case2()
{
	int		n = 5;
	char	str[20] = "\0\0abcde\0\0\0\0\0\0\0\0\0\0\0";
	char	*src;
	char	*dst;

	src = &str[2];
	dst = &str[0];

	MEMMOVE(src, dst, n);

	printf("src = %s\n", src);
	printf("dst = %s\n", dst);

	return 0;
}

int me_case3()
{
	int		n = 5;
	char	str[20] = "abcde\0\0\0\0\0\0\0\0\0";
	char	*src;
	char	*dst;

	src = &str[0];
	dst = &str[2];

	MEMCOPY(src, dst, n);

	printf("src = %s\n", src);
	printf("dst = %s\n", dst);

	return 0;
}

int me_case4()
{
	int		n = 5;
	char	str[20] = "\0\0abcde\0\0\0\0\0\0\0\0\0";
	char	*src;
	char	*dst;

	src = &str[2];
	dst = &str[0];

	MEMCOPY(src, dst, n);

	printf("src = %s\n", src);
	printf("dst = %s\n", dst);

	return 0;
}
