#include <stdio.h>

int cnt;

int thisisA();
int thisisB();
int thisisC();
int thisisD();

void main()
{
	if(thisisA() && thisisB())
	{
		printf("And logical operator has been executed!\n");
	}

	if(cnt != 2)
	{
		printf("But both of func are not executed : cnt = %d\n",cnt);
	}
	cnt = 0;

	if(thisisC() || thisisD())
	{
		printf("Or logical operator has been executed!\n");
	}

	if(cnt != 2)
        {
                printf("But both of func are not executed : cnt = %d\n",cnt);
        }

}

int thisisA()
{
	cnt ++;
	printf("A func has been executed!\n");
	return 0;
}

int thisisB()
{
	cnt ++;
	printf("B func has been executed!\n");
	return 1;
}

int thisisC()
{
	cnt++;
	printf("C func has been executed!\n");
	return 1;
}

int thisisD()
{
	cnt++;
	printf("D func has been executed\n");
	return 0;
}
