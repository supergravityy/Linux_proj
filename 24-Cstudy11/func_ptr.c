#include <stdio.h>

void hello()
{
	printf("Hello, World!\n");
}

void bonjour()
{
	printf("bonjour le monde!\n");
}

void main()
{
	void (*fp)(); // 반환값과 매개변수가 없는 함수포인터 fp 선언
	
	fp = hello; // 함수의 첫시작주소 넘기기
	fp();

	fp = bonjour;
	fp();
}
