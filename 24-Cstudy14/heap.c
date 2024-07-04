#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int cur_idx ;

typedef struct human
{
	int num;
	char name[20];
}human;


void add_man(human * IDs)
{
	for(;cur_idx < MAX;)
	{
		IDs[cur_idx].num = (cur_idx+1)*2;
        	sprintf(IDs[cur_idx++].name,"Man%d",cur_idx+1);
		// 버퍼의 주소에 포멧형식대로 복사시킴
	}
}

void print(human * IDs)
{
	int i = 0;
	
	for(;i<MAX;i++)
	{
		printf("\nid : %d, name : %s\n",IDs[i].num,IDs[i].name);
	}
}

void main()
{
	human *IDs;

	IDs = (human*)malloc(sizeof(human)*MAX);

	add_man(IDs);
	print(IDs);

	free(IDs);
}
