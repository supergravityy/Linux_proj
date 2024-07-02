#include <stdio.h>

int cnt = 10;

int first()
{
	printf("this is first seq\n");
	return 1;
}

int forth()
{
	printf("this is last seq\n");
	return 1;
}

int second()
{
	printf("this is second seq : %d\n",cnt);
	return cnt--;
}

int main()
{
	int a = 10;

	int b = 3;
	while(a>b) // while문은 조건변수가 0이면 멈춘다 
	{
		printf("a : %d\n",a--);
	}
	printf("\n\n\n\n\n\n\n\n\n\n");

	for(/*초기값*/first();/*조건식*/second();/*실행부분*/forth())
		printf("this is third seq\n");
	
	// do while 문 처럼 사용이 가능하다 
	return 1;
}
