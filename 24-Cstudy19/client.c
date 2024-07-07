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

int stoHEX(char fi, char sc);
void err_handling(char *msg);
void * send_msg(void *arg);
void * recv_msg(void *arg);

char msg[BUFFSIZE];

int main(int argc, char ** argv)
{
	int sock;
	struct sockaddr_in serv_addr;
	pthread_t send_thread, recv_thread;
	void *thread_result;

	sock = socket(PF_INET, SOCK_STREAM,0);

	if(sock== -1)
		err_handling("socket error\n");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;

	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(7889);

	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))==-1)
		printf("connect error");

	unsigned char msg[50] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	while(1)
	{
		printf("send : \n");
		write(sock,msg,25);

		sleep(1);
	}

	close(sock);
	return 0;
}

void err_handling(char *msg)
{
        fputs(msg, stderr);
        fputc('\n', stderr);
        exit(1);
}

