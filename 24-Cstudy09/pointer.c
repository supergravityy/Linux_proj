#include <stdio.h>

void main()
{
	int a;
	int *pa;
	int **ppa;

	a = 3;
	printf("a = %x\n",a);
	printf("&a = %x\n",&a);

	pa = &a;
	printf("pa = %x\n",pa);
	printf("*pa = %x\n",*pa);
	printf("&pa = %x\n",&pa);
	
	ppa = &pa;
	printf("&ppa = %x\n", &ppa);
	printf("ppa = %x\n", ppa);
	printf("*ppa = %x\n",*ppa);
	printf("**ppa = %x\n",**ppa);

	// printf("***ppa = %x\n",***ppa)
	// a의 3도 주소로 생각하면서 접근하려 하면, 리눅스가 프로세스를 죽임
}
