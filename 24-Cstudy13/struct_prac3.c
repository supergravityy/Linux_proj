#include <stdio.h>
#include <string.h>

typedef struct 
{
	char name[10];
	int age;
	char sex;
}human;

typedef struct
{

	int s_id;
	human man;
}student;

typedef struct
{
	int s_id;
	human *man;
}student2;

void func(student* st1)
{
	st1->s_id = 15;
	strcpy(st1->man.name,"hyunsu");
}

void func2(student2* st2)
{
	st2 -> s_id = 17;
	strcpy(st2->man->name, "minsu");
}


void main()
{
	student st1;

	st1.s_id = 10;
	strcpy(st1.man.name,"sungsu");

	printf("id : %d, name : %s\n",st1.s_id, st1.man.name);

	func(&st1);
	printf("id : %d, name : %s\n",st1.s_id, st1.man.name);

	student2 st2;
	human hm;
	st2.man = &hm;
	// 학생2 구조체는 human의 주소값을 받기에, 
	// 그 주소에 들어갈 변수를 따로 선언해주기

	func2(&st2);
	printf("id : %d, name : %s\n",st2.s_id, st2.man->name);
}
