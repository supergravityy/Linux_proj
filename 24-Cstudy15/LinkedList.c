#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int id;
	char name[30];
	struct Node * next;
}Node;

Node* head;
Node* tail;

int insert(int id, char * name)
{
	Node* data = (Node*)malloc(sizeof(Node));
	data->next = NULL;
	
	data->id = id;
	if(name!=NULL )
		strcpy(data->name,name);

	if(head == NULL) // 처음이냐?
	{
		head = data; // 네
		tail = data;
		return 1;
	}

	else // 아니요
	{
		Node* temp = head; 

		while(temp->next)
			temp = temp->next;

		temp->next = data;
		tail = data;
	}
	return 1;
}

void print()
{
	if(head == NULL)
		return;

	Node* temp = head;
	while(temp->next)
	{
		printf("\nid : %d, name : %s\n",temp->id,temp->name);
		temp = temp->next;
	}

	printf("\nid : %d, name : %s\n",temp->id,temp->name);
	// 마지막 노드는 무조건 next 멤버가 null 이기에
}


void stack_pop(Node* basket) // 제일 마지막게 pop됨
{
	if(head == NULL)
		return;

	// 가장 끝 노드 이전 노드를 찾기위한 여정 
	Node* temp = head;
	Node* before = NULL;

        while(temp->next)
	{
		before = temp;
        	temp = temp->next;
	}

	basket->id = tail->id;
	strcpy(basket->name,tail->name); // 매개변수에 값 담기

	free(tail); // 꼬리 제거
	tail = before;

	if (before != NULL) // 연결 리스트가 원래 하나밖에 없었을 때 빼고 
        	before->next = NULL; // 이제 끝 이전 노드가 끝이다 

    	if (tail == NULL) // 연결 리스트가 원래 하나밖에 없었을 때
        	head = NULL;
       
}

void queue_pop(Node* basket)
{
	if(head == NULL)
		return;

	basket->id = head->id;
	strcpy(basket->name,head->name);

	Node* temp;
	if(head->next != NULL)
		head = head->next;
	else
	{
		head = NULL;
		tail = NULL;
	}
}

int find(int id, Node* basket)
{
	if(head == NULL)
		return 0;

	// 머리부터 발끝까지 전부 탐색
	Node* temp = head;
	while(temp)
	{
		if(temp->id == id)
		{
			basket->id = temp->id;
			strcpy(basket->name,temp->name);
			return 1;
		}
		temp = temp->next;
	}
		
	return 0;
}

void main()
{
	char name[20] ;
	for(int i =0; i < 10; i++)
	{
		sprintf(name,"test%d",i);
		insert(i,name);
	}

	print();
	puts("=======================================");

	Node tempData;

	for(int i =0; i <10; i++)
	{
		stack_pop(&tempData);
        	printf("\nlast node Data\nid : %d, name : %s\n",tempData.id,tempData.name);
	}

        for(int i =0; i < 10; i++)
        {
                sprintf(name,"test%d",i);
                insert(i,name);
        }

	puts("=======================================");
	if(find(8,&tempData))
		printf("wanted id : %d, name : %s\n",tempData.id,tempData.name);

	else
		printf("error!\n");
	puts("=======================================");

	for(int i =0; i <10; i++)
        {
                queue_pop(&tempData);
                printf("\nfirst node Data\nid : %d, name : %s\n",tempData.id,tempData.name);
        }
	

	return;

}
