CC = gcc
++ = g++
EXE = test_makefile.out
# OBJS = main.o sum.o

LDFLAGS = -lpthread # 추가라이브러리를 추가하는 터미널옵션도 변수로 둘 수 있다.
DEFINES = -DDEBUG # 터미널창 define도 변수로 설정가능하다
STRIPS = strip # strip은 실행파일 전에 추가로 명령을 내리면 필요없는 코드부분을 삭제하고 실행
#(디버그 심볼같이 실행에 필요없는 정보를 삭제 )

CFLAGS = -I./include $(DEFINES)  
# 이런 컴파일 옵션들은 명령어 단에 직접치지 말고, 
# 꼭 CFLAGS라는 변수명으로 선언해주자. 다른 변수명은 안됨.

C_SRC = $(wildcard *.c)
OBJS = $(C_SRC:.c = .o)
# 와일드카드 문법은 해당 디렉터리의 모든 소스파일들을 특정 변수로 추가시킨다는 뜻
# 밑의 문법은 소스파일들을 전부 obj 파일로 바꾼다는 뜻
# 앞으로 소스를 추가하면, 그냥 터미널에 추가하자마자 전부 다 컴파일되서 실행됨 

# 크로스 컴파일의 경우
CROSS = arm-
CRCC = $(CROSS)gcc
# 그럼, CRCC를 사용시, arm-gcc 가 된다. 

# all : main.o sum.o
#       gcc -o test_makefile.out main.o sum.o
# 
# 원래는 이렇게 써야 한다.

# all : main.o sum.o
#	gcc -o test_makefile.out $^
#
# 의존성 파일들을 전부 추가하는 명령어 $^

# $(EXE) : $(OBJS)
#	gcc -o test_makefile.out $^
# 이미 EXE와 필요한 파일들을 선언했기 때문에 명령어 사용가능

# $(EXE) : $(OBJS)
#	gcc -o $@ $^
# 이렇게 선언시, @는 $(EXE) : 에서 EXE로 선언된 파일명을 받음

all : $(EXE)
	echo completed!!!!

$(EXE) : $(OBJS)
	$(CC) -o $@ $^
# gcc도 변수로 두고  $로 사용하였다.

main.o : main.c
	gcc -c main.c

sum.o : sum.c
	gcc -c sum.c
# 의존파일이 있는 명령어들은 make만 써도 자동적으로 실행됨

clean :
	rm *.o
# 의존파일이 없는 명령어들은 따로 make써주고 명령어를 적어주기 
# make clean

delete : 
	rm test_makefile

delete.out :
	rm *.out

good : 
	echo good
