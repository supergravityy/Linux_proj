#include <stdio.h>
#include <stdbool.h>

bool isRunning()
{
	return true;
}

void main()
{
	(isRunning()) ? printf("is running now\n"):printf("is not running now\n");
}
