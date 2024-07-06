#include <stdio.h>

void main()
{
	FILE* fp;
	char ch;

	fp = fopen("text.txt","a");

	if(fp == NULL)
		printf("file open error\n");

	fprintf(fp, "hello hello~ 한글도 되나요? \n");

	fclose(fp);

	fp = fopen("text.txt","r");

        if(fp == NULL)
                printf("file open error\n");

	while(1)
	{
		ch = fgetc(fp);
		
		if(ch == EOF)
                        break;

		putchar(ch);
	}

	fclose(fp);
}
