#include <stdio.h>

int main()
{
	double d = 3.14;
	int i =2;

	printf("%lf\n",(d+i)); // 이런식으로 사용시 의도치 않는 값이 나올 수 있다.
			       
	printf("%lf\n",(double)i +d); // 형변환에 유의할 것.

	int integer = 500;
	printf("%u\n",(unsigned char)integer);

	return 0;
}
