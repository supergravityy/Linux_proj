#include <pthread.h>
#include <stdio.h>

int a;
pthread_mutex_t mutex; // 뮤텍스 선언

void * thread_DO(void * th_id)
{
        printf("arg : %d\n",(int)th_id);

        while(1)
        {
		pthread_mutex_lock(&mutex); //뮤텍스로 context switching 방지

                printf("thread%d : a[%d]\n",(int)th_id,a++);
		
		pthread_mutex_unlock(&mutex); // lock 해제

                sleep(2);
        }

        return NULL;
}

int main()
{
        pthread_t thread1 , thread2;        
	int th1_id = 77;
        int th2_id = 88;

	pthread_mutex_init(&mutex,NULL); // 뮤텍스 초기화하기
	// 뮤텍스 초기화함수 (뮤텍스 주소값, 옵션)
	// NULL로 하면, fast 옵션으로 실행

        if( !pthread_create(&thread1, NULL, thread_DO,(void*)th1_id))
		printf("created thread1 successfully!\n");

        else
                printf("failed to create thread1\n");
        
        if(!pthread_create(&thread2, NULL, thread_DO, (void*)th2_id))
                printf("created thread2 successfully!\n");
        else
                printf("failed to create thread2\n");

        while(1)
        {
                printf("main thread loop!\n");
                sleep(1);
        }


        if( !pthread_join(thread1, NULL))
		printf("thread1 has been terminated successfully!\n");

        if(!pthread_join(thread2,NULL))
                printf("thread2 has been terminated successfully!\n");

	pthread_mutex_destroy(&mutex); // 무텍스 삭제
        return 0;

}
