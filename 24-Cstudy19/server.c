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

int g_clnt_sockets[CLNT_MAX];
int g_clnt_cnt = 0;

int main(int argc, char ** argv)
{
	int serv_socket, clnt_socket;
	
	struct sockaddr_in clnt_addr;
	int clnt_addr_size;

	struct sockaddr_in serv_addr;

	/*---------------------------*/
	// 1. 소켓만들기
	/*---------------------------*/

	serv_socket = socket(PF_INET,SOCK_STREAM,0); 
	// PF_INET = ipv4를 사용 (프로토콜에 관해서 사용해서 P), SOCK_STREAM = TCP사용 
	// PF_INET = ipv6, SOCK_DGRAM = UDP사용, SOCK_RAW = 가공하지 않은 소켓(공유기 개발자)
	// 0을 사용함으로써, auto로 TCP에 대한 마지막 설정을 부여

	/*---------------------------*/
        // 2. bind 과정
        /*---------------------------*/
	
	serv_addr.sin_family = AF_INET; // ipv4를 사용 (주소에 관해서 사용해서 A)
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 내 현재 PC의 IP사용
	// host 정렬 방식을 네트워크 방식의 unsigned int형으로 (리틀엔디안 -> 빅엔디안)
	// 어떤 주소로 bind 할건지 설정
	serv_addr.sin_port=htons(7889); //
	// host 정렬 방식을 네트워크방식의 short형으로
	// 첫번째 메인 파라미터에 포트번호를 전달하려면 atoi(argv[1])
	
	if(bind(serv_socket,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) == -1) // 에러시 -1반환
	{
		printf("bind error\n");
	}
	
	/*---------------------------*/
        // 3. listen 과정
        /*---------------------------*/

	if(listen(serv_socket,5) == -1)
	// 두번째 파라미터는 대기할 수 있는 최대 클라수 
	{
		printf("listen error\n");
	}


	char buff[200]; // 받아올 데이터 저장공간
	int recv_len = 0;
	while(1)
	{

	/*---------------------------*/
        // 4. accept 과정
        /*---------------------------*/

		clnt_addr_size = sizeof(clnt_addr);
		clnt_socket = accept(serv_socket,(struct sockaddr *) &clnt_addr, &clnt_addr_size);
		// clnt_socket에 통신할 클라의 ip 정보를 담아서 가져옴

		//g_clnt_sockets[g_clnt_cnt++] = clnt_socket;
		// 클라 명단에 올리기
	
	/*---------------------------*/
        // 5. receive 과정
        /*---------------------------*/

		while(1)
		{
			// 스레드를 할 수 없기에 1:1 통신만 가능 한번 들어오면 무한루프
                	recv_len = read(clnt_socket,buff,sizeof(buff));

			printf("recv : ");
                	for(int i =0; i < recv_len; i++)
                        	printf("%02X ",(unsigned char)buff[i]);
                	printf("\n");

			// recv 한 data 출력
		}
	}

	//close(socket);
	return 0;
}
