#include <stdio.h>

void main()
{
	char hello[] = "hello linux\n";
	
	// 출력
	fprintf(stdout,"hello linux\n");
	write(1,"hello linux\n",sizeof(hello));
}
