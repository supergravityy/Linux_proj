#include <pthread.h>
#include <stdio.h>

int a;

void * thread_DO(void * th_id)
{
	printf("arg : %d\n",(int)th_id);

	while(1)
	{
		printf("thread%d : a[%d]\n",(int)th_id,a++);
		sleep(2);
	}

	return NULL;
}

int main()
{
	pthread_t thread1 , thread2; // pthread_t는 리눅스에서 unsigned long int 와 똑같음 (정수) -> 식별자
	int th1_id = 77;
	int th2_id = 88;

	if( !pthread_create(&thread1, NULL, thread_DO,(void*)th1_id)) // 스레드를 만드는 함수
	// 함수의 매개변수 (스레드 포인터, 스레드 특성을 지정하는 구조체 포인터, 실행할 함수에 대한 포인터 )
	// 특성은 스레드의 스택크기, 우선순위 등의 특성을 설정 -> NULL로 전달시, 기본특성 사용
	// 나머지는 스레드에게 할당된 함수에 들어갈 파라미터
		printf("created thread1 successfully!\n");

	else
		printf("failed to create thread1\n");
	// thread_create 함수는 성공하면 0을 반환, 아니면 오류코드를 반환
	


	if(!pthread_create(&thread2, NULL, thread_DO, (void*)th2_id))
		printf("created thread2 successfully!\n");
	else
		printf("failed to create thread2\n");

	while(1)
	{
		printf("main thread loop!\n");
		sleep(1);
		// 메인코드도 어떻게 보면 또다른 스레드여서, 메인문이 리턴되는 순간 프로세스가 종료됨. -> 원하는 동작 실행X
	}


	if( !pthread_join(thread1, NULL)) // 스레드가 종료될 때까지 호출한 스레드를 블록(block) 상태로 대기시키는 함수
	// 함수의 매개변수 (종료를 기다릴 대상 스레드, 스레드가 반환한 값을 저장할 포인터 주소)
	// NULL 일때는 반환값을 무시
		printf("thread1 has been terminated successfully!\n");

	if(!pthread_join(thread2,NULL))
		printf("thread2 has been terminated successfully!\n");

	return 0;
	
}
