#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define CLNT_MAX 10
#define BUFFSIZE 200

int g_clnt_sockets[CLNT_MAX];
int g_clnt_cnt = 0;

pthread_mutex_t mtx;

void send_all_clnt(char *msg, int my_socket)
{
	pthread_mutex_lock(&mtx); // 역시나 전역변수를 다루기에

	for(int idx = 0; idx < g_clnt_cnt; idx++)
	{
		if(g_clnt_sockets[idx] == my_socket)
			continue;

		write(g_clnt_sockets[idx], msg, strlen(msg));
	}

	pthread_mutex_unlock(&mtx); // 뮤텍스 락을 걸어두기 
}

void * clnt_connect(void *arg) // 연결이 되면, read를 여기서 함.
{
	int clnt_socket = *(int *)arg; 	// 파라미터는 클라의 소켓식별자
	int str_len = 0;		// 몇바이트를 받았냐

	char msg[BUFFSIZE]; // 수신받을 버퍼

	while(1)
	{
		sleep(1);
		if( (str_len = read(clnt_socket,msg,sizeof(msg))) <= 0) // 반환시, 읽어들인 바이트 수, 실패시 -1
		{
			if(str_len == 0)
				printf("\nclient [%d] disconnected\n",clnt_socket); // 세션이 끊어진 상황
			else 
				perror("\nread error");

			sprintf(msg,"client[%d] disconnected\n",clnt_socket);
			send_all_clnt(msg,clnt_socket);	// 연결이 끊기면 다른 모든사람들한테 메시지출력

			break; // 바로 루프 탈출
		}

		else
		{
			printf("read client[%d] msg : %s\n", clnt_socket,msg); // 받은 메시지 서버콘솔에 출력
			send_all_clnt(msg,clnt_socket); // 본인제외 모든사람들한테 메시지 뿌리기
		}
	}

	pthread_mutex_lock(&mtx); // 이 부분도 크리티컬 영역이기에 뮤텍스 락

	for(int idx = 0; idx <g_clnt_cnt; idx++)
	{
		if(clnt_socket == g_clnt_sockets[idx]) // 클라 목록에서 삭제
		{
			for(; idx < g_clnt_cnt-1; idx++) // 뒤에걸 덮어써서 지워버림
				g_clnt_sockets[idx] = g_clnt_sockets[idx+1];
			break;
		}
	}		
	g_clnt_cnt--; // 접속자 수 -1

	pthread_mutex_unlock(&mtx);

	close(clnt_socket);     // 소켓 부수기	
	pthread_exit(0);	// 완전히 리소스를 반환하기위해서 	
	return NULL;
}

int main(int argc, char ** argv)
{
	int serv_socket, clnt_socket;
	
	struct sockaddr_in clnt_addr;
	int clnt_addr_size;

	struct sockaddr_in serv_addr;

	pthread_t serv_thread;
	pthread_mutex_init(&mtx,NULL); // 뮤텍스 초기화

	/*---------------------------*/
	// 1. 소켓만들기
	/*---------------------------*/

	serv_socket = socket(PF_INET,SOCK_STREAM,0); 

	/*---------------------------*/
        // 2. bind 과정
        /*---------------------------*/
	
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 	
	serv_addr.sin_port=htons(7889);

	if(bind(serv_socket,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) == -1) 	
		printf("bind error\n");
	
	
	/*---------------------------*/
        // 3. listen 과정
        /*---------------------------*/

	if(listen(serv_socket,5) == -1)
	{
		printf("listen error\n");
		return 1;
	}
	else
		printf("server is listening now!\n");


	char buff[200]; 	
	int recv_len = 0;

	while(1)
	{

	/*---------------------------*/
        // 4. accept 과정
        /*---------------------------*/

		clnt_addr_size = sizeof(clnt_addr);
		clnt_socket = accept(serv_socket,(struct sockaddr *) &clnt_addr, &clnt_addr_size);

		if (clnt_socket == -1) 	
		{
            		perror("\naccept error");
            		continue;
        	}
		else
			printf("server and client[%d] is connected now!\n",clnt_socket);
	
	/*---------------------------*/
        // 5. receive 과정
        /*---------------------------*/

		pthread_mutex_lock(&mtx);
		g_clnt_sockets[g_clnt_cnt++] = clnt_socket; // 클라 소켓 목록에 저장
		pthread_mutex_unlock(&mtx);
		// 전역변수 사용 부분은 크리티컬 영역이다 

		pthread_create(&serv_thread,NULL,clnt_connect,(void*) &clnt_socket);
		printf("Thread was made for the client[%d] right now\n", clnt_socket);		
	}
	
	pthread_mutex_destroy(&mtx);
	pthread_join(serv_thread,NULL);
	return 0;
}
