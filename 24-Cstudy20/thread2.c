#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a;

void * thread1_DO(void * th_id)
{
	int *result = malloc(sizeof(int)); // 힙영역, data 영역에 있어야 리턴값을 알수있음
	
	printf("arg : %d\n",(int)th_id);

	int counter = 0;
        while(counter < 20)
        {
                printf("thread%d : a[%d]\n",(int)th_id,a++);
                sleep(1);
                counter++;
        }

	*result = counter; // 카운터값을 반환할 것이다. 
	printf("thread1 : exiting with counter %d", *result);
	pthread_exit((void*) result);
	// 스레드를 종료하면서 결과 반환 이때 리턴값은 무조건 void* 일것!!!
}

void * thread2_DO(void * th_id)
{
	int *result = malloc(sizeof(int));

        printf("arg : %d\n",(int)th_id);
	
	int counter = 0; 
        while(counter < 30)
        {
                printf("thread%d : a[%d]\n",(int)th_id,a++);
                sleep(1);
		counter++;
        }

	*result = counter;
        printf("thread2 : exiting with counter %d", *result);
	
	return (void *)result; // pthread_exit 이나, return (void*)이나 결과는 같다.
}

int main()
{
	pthread_t threads[2]; 
	int th1_id = 77;
	int th2_id = 88;

	if( !pthread_create(&threads[0], NULL, thread1_DO,(void*)th1_id)) 
		printf("created thread1 successfully!\n");
	else
		printf("failed to create thread1\n");
	


	if(!pthread_create(&threads[1], NULL, thread2_DO, (void*)th2_id))
		printf("created thread2 successfully!\n");
	else
		printf("failed to create thread2\n");

	int counter = 0;
	while(1)
	{
		printf("main thread loop!\n");
		sleep(1);

		counter++;
		if(counter >= 5)
			break;
	}
	printf("main thread has escaped loop! with counter : %d\n", counter);

	void *retVal1;
        void *retVal2; // 힙영역에 선언한 리턴값의 주소를 받을 포인터변수 생성

	if( !pthread_join(threads[0], &retVal1)) // 리턴값은 이중포인터이기에
		printf("thread1 has been terminated successfully! with counter : %d\n",*(int *)retVal1 );
	// retVal은 1차 포인터변수이기에, join에서 retval의 주소를 넘겨주었다. 그렇기에, *(int *)로만 해주면된다.

	if(!pthread_join(threads[1], &retVal2))
		printf("thread2 has been terminated successfully! with counter : %d\n",*(int *)retVal2 );

	free(retVal1);
	free(retVal2);
	return 0;
	
}

