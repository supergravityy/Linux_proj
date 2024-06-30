#include <stdio.h>

void main()
{
	int i=0;
	unsigned int ui=1;
	char c=2;
	unsigned char uc=3;
	short s=5;
	unsigned short us = 6;
	long l = 7;
	unsigned long ul = 8;
	float f = 9.;
	//unsigned float uf = 10.0;
	double d = 11.0;
	//unsigned double ud = 12.0;
	long long ll = 13;
	unsigned long long ull = 14;

	printf("int i = %d\n", i);
    	printf("unsigned int ui = %u\n", ui);
    	printf("char c = %d\n", c);  // %d 사용
    	printf("unsigned char uc = %u\n", uc);  // %u 사용
    	printf("short s = %d\n", s);
    	printf("unsigned short us = %u\n", us);
    	printf("long l = %ld\n", l);
    	printf("unsigned long ul = %lu\n", ul);
    	printf("float f = %f\n", f);
    	printf("double d = %f\n", d);
    	printf("long long ll = %lld\n", ll);
    	printf("unsigned long long ull = %llu\n", ull);

	//unsigned float은 안된다. 자료형으로 선언 자체가 안됨
}
