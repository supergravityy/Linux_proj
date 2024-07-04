#include <stdio.h>
#include <string.h>

typedef struct 
{
    int id;
    char name[20];
} DAT;

void struct_init(DAT* data) 
{
    data->id = 10;
    strcpy(data->name, "sungsu");
}

int main() 
{
    DAT data1;

    struct_init(&data1);

    printf("data : %d, %s\n", data1.id, data1.name);
    printf("just data1 : %p\n", data1);
    printf("addr data.id : %p\n", &data1.id);
    printf("addr data1 : %p\n", &data1);

    // 인스턴스의 첫번째 주소값은 인스턴스 첫멤버의 주소값과 같다.
    // 배열처럼 작동
    return 0;
}





















	

	


