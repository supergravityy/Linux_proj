#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int fd;

void main()
{
	fd = open("test.txt",O_WRONLY|O_APPEND);
	// fopen의 원형
	printf("fd : %d\n",fd);
	// fd = 0 표준입력 (키보드)
	// fd = 1 표준출력 (콘솔, 혹은 설정한대로)
	// fd = 2 에러출력 (콘솔) -> 3번과는 다른 스트림
	// fd = 3,4 (파일)

	char test[] = "this is for test\n";
	write(fd,test,sizeof(test));
	// fwrite의 원형

	close(fd);
}
