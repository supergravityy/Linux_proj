#include <stdio.h>

#define MAX 10000

void main()
{
	int array[MAX];

	for(int i = 0; i<MAX; i++)
	{
		array[i] = 2*i;
		printf("array[%d] = %d\n",i,array[i]);
	}

	int a = array;
	printf("a = %d\n",a);
	return;
}
