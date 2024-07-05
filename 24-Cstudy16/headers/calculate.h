#pragma once

#include <stdio.h>

#ifdef SUM

int calculate(int a, int b)
{
	printf("add\n");
	return a+b;
}

#else

int calculate(int a, int b)
{
	printf("multiple!\n");
	return a*b;
}

#endif


