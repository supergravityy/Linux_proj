#include <stdio.h>

FILE*fp;
FILE*fp2;

void main()
{
	fp = fopen("test.txt","a");
	fp2 = fopen("test2.txt","a+");

	printf("fp1's fd : %d\n", fp->_fileno);
	printf("fp2's fd : %d\n", fp2->_fileno);

	fclose(fp);
	fclose(fp2);
}
