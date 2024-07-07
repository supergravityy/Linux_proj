#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFFSIZE 100
#define NAMESIZE 20

// 정적변수나 전역변수를 사용하지 않아서 critical Area 없다고 생각 -> 뮤텍스 필요 X

void * recv_msg(void * arg)
{
	int serv_socket = *(int*)arg;
	char buffer[BUFFSIZE + NAMESIZE +10];
	int str_len;

	while(1)
	{
		if((str_len = read(serv_socket,buffer,sizeof(buffer))) < 0) // 서버와의 세션 끊김
		{
			if(str_len == -1)
				printf("\nyour session with server has been disconnected!\n");
			else
				perror("\nread error\n");
			break;
		}
		sleep(1);
		printf("\n%s",buffer); // 이미 아이디도 메시지안에 들어있음
	}
	
	pthread_exit(0);
	return NULL;
}

int main(int argc, char ** argv)
{
	int serv_socket;
	struct sockaddr_in serv_addr;
	pthread_t recv_thread; // 서버에게서 받을 함수동작 스레드
	char userID[NAMESIZE];

	if(argc != 2) // 실행파일 이름 + ID
	{
		printf("Type your ID correctly!\n");
		return 0;
	}

	strcpy(userID,argv[1]); // client를 실행할 때, 첫 인자로 ID를 입력
	printf("your id : %s\n",userID);

	/*-----------------------------------*/
	// 1. socket 생성
	/*-----------------------------------*/

	serv_socket = socket(PF_INET, SOCK_STREAM,0);

	if(serv_socket == -1)
	{
		printf("socket creation error!\n");
		return 0;
	}
	
	memset(&serv_addr, 0, sizeof(serv_addr)); // 서버주소 구조체 초기화
	serv_addr.sin_family = AF_INET;		  // ipv4

	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(7889);

	/*-----------------------------------*/
 	// 2. connect 과정
	/*-----------------------------------*/

	if(connect(serv_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
	{
		printf("connect error\n");
		return 0;
	}

	char msg[BUFFSIZE];
	char send_msg[BUFFSIZE + NAMESIZE + 10];

	pthread_create(&recv_thread,NULL,recv_msg,(void *) &serv_socket); // 다른사용자의 msg를 받을 함수를 스레드로
	printf("Thread was made for receiving right now\n");
	
	while(1)
	{
		printf("chat input[99] : ");
		fgets(msg, BUFFSIZE-1, stdin); // 메시지 입력받기 (오버플로 방지)

		sprintf(send_msg,"[%s] : %s\n",userID, msg); // ID와 조합해서 전송할  메시지 만들기
		// snprintf를 사용하면 오버플로 문제 해결

		printf("\nsend : %s", msg);
		write(serv_socket, send_msg, strlen(send_msg)+1 ); // NULL도 같이 보내야 하기에

		sleep(1);
	}

	close(serv_socket);
	return 0;
}
