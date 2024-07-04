#include <stdio.h>

char * string_copy(char * dst, char * src);
size_t string_length(const char *str);
int string_compare(const char *str1, const char *str2);

void main()
{
	char str[20] = "hello linux\n";
	char str_c[20] = "ready\n";

	char str1[20] = "this is test\n";
	char str2[20] = "this is Test\n";

	printf("before strcpy : %s",str_c);

	string_copy(str_c,str);

	printf("after strcpy : %s",str_c);

	printf("string length : %ld\n",string_length(str_c));

	int diff;
	if(!(diff = string_compare(str1,str2)))
		printf("both of strings are same!\n");
	else
		printf("both of strings are not same! : %d\n",diff);
}

int string_compare(const char *str1, const char *str2)
{
	// 두 문자열의 각 문자들을 빼서, 0이 아니면 그 차이를 함수로 출력
	
	int idx = 0;
	
	while(str1[idx] != 0 && str2[idx] != 0)
	{
		if(str1[idx] - str2[idx])
			return str1[idx] - str2[idx]; // 두 문자가 서로 다를때, 그 차이를 출력
		idx++;

	}

	if(str1[idx] - str1[idx])
		return str1[idx] - str1[idx]; // 둘중에 하나가 null -> 길이가 다르다

	return 0; // 두 문자열이 완벽히 똑같음
}

char* string_copy(char * dst, char * src)
{
	while(*src) // ascii에서 0 은 null
	{
		*dst++ = *src++;
	}

	return dst;
}

size_t string_length(const char *str)
{
	int cnt = 0;
	if(str != NULL)
	{
		
		while(1)
		{
			if(str[cnt++] == 0)
				break;
			else
				cnt++;
		}
	}

	else
		return -1;

	return cnt;
}
