#include <stdio.h>

int add(int a, int b)    // int형 반환값, int형 매개변수 두 개
{
    return a + b;
}

int mul(int a, int b)    // int형 반환값, int형 매개변수 두 개
{
    return a * b;
}

void main()
{
    int (*fp)(int, int);    // int형 반환값, int형 매개변수 두 개가 있는 함수 포인터 fp 선언

    fp = add;                      
    printf("%d\n", fp(10, 20));   

    fp = mul;                      
    printf("%d\n", fp(10, 20));
}
