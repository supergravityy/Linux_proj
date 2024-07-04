#include<stdio.h>

typedef struct
{
	int ID;
	char Name[21];
	char phoneNum[31];
	char sex;
}DATA;
// pragma 를 안쓴 구조체는 총합크기를 4바이트 단위로 읽음

#pragma pack(push,1)

typedef struct 
{
        int ID;
        char Name[21];
        char phoneNum[31];
        char sex;
}DATA2;

#pragma pack(pop)

void main()
{
	DATA data1;
	DATA2 data2;
	
	printf("non_pragma struct size : %ld\n",sizeof(data1));
	printf("pragma struct size : %ld\n", sizeof(data2));

}
