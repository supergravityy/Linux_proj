#include <stdio.h>

void main()
{
	char str[20] = "hello";

	char str1 = 'H';
	char str2 = 'E';
	char str3 = 'L';
	char str4 = 'L';
	char str5 = 'O';
	char str6 = '\0';

	printf("%s\n",str);

	printf("%c%c%c%c%c%c\n",str1,*(&str1+1),*(&str1+2),*(&str1+3),*(&str1+4),*(&str1+5));
}
