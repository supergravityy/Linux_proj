#include <stdio.h>

void main(int argc, char* argv[])
{
	// argument vector는 문자열 배열이기 때문에
	if(argc > 0)
		for(int i =0; i <argc; i++)
			printf("op[%d] : %s\n",i,argv[i]);
}
