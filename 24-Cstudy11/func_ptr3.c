#include <stdio.h>

int test(char p1, char p2, char p3, char p4, char p5, char p6, char p7)
{
	return p1 + p2 +p3 +p4+ p5+ p6+p7;
}

void main()
{
	int (*fp)(char,char,char,char,char,char,char);

	fp = test;

	printf("%d\n",fp(1,2,3,4,5,6,7));
}


