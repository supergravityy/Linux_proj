#include <stdio.h>

void main()
{
	// 표준함수는 컴파일러가 다르더라도 최소한 이 라이브러리 안의 함수는 구현해준다.
	// gcc 뿐만 아니라, gcc-arm 에서도 호환이 되는 문법이다.
	
	int A;

	printf("정수를 입력 : __\b\b ");
	scanf("%c",&A);

	printf("입력된 값 : %c\n",A); // 문자로 출력
}
