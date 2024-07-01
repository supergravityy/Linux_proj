#include <stdio.h>

void main()
{
	char GPIO = 0b00010101; // 해당 GPIO핀을 11111011로 만들어야 한다.
	
	// 아이디어 
	// ~(11111011) 연산시, 00000100 으로 나오게 된다.
	// 그럼, 이 GPIO를 전체NOT 연산을 거친 비트로 만들고, NOT을 걸면 나오게 된다.
	
	GPIO &= ~(1 << 2);
	
	// 출력 부분
	char printVal = 0;

	printVal = GPIO & (1<<7); // 0x80 & ch 를 하면, MSB만 결과로 출력되게 된다.
	printVal = printVal >> 7; // 그리고 1만을 출력하기 위해,  해당 MSB를 LSB로 내려서 1또는 0으로 만든다.
	printf("%d ",printVal);

	printVal = GPIO & (1<<6);
	printVal = printVal >> 6;
	printf("%d ",printVal);

	printVal = GPIO & (1<<5);
        printVal = printVal >> 5;
        printf("%d ",printVal);

	printVal = GPIO & (1<<4);
        printVal = printVal >> 4;
        printf("%d ",printVal);

	printVal = GPIO & (1<<3);
        printVal = printVal >> 3;
        printf("%d ",printVal);

	printVal = GPIO & (1<<2);
        printVal = printVal >> 2;
        printf("%d ",printVal);

	printVal = GPIO & (1<<1);
        printVal = printVal >> 1;
        printf("%d ",printVal);

	printVal = GPIO & 0x01;
	
	printf("%d\n",printVal);

}
