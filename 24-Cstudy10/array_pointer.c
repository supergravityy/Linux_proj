#include <stdio.h>

void main()
{
	int a;
	int *pa;

	int arr[1];

	pa = &a;
	*pa = 0x77;

	arr[0] = 0x55;

	int Arr[3];
	*(Arr) = 0x67;
	*(Arr+1) = 0x78;
	*(Arr+2) = 0x89;

	char Arrc[3];
	*(Arrc) = 0x12;
	*(Arrc+1) = 0x23;
	*(Arrc+2) = 0x34;

}
