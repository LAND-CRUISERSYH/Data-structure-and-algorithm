#include<stdio.h>
#include<string.h>

//#define SIZE 20
//
//typedef struct
//{
//	char ch[SIZE + 1];                 //存储串的一维数组
//	int length;							//串的当前长度
//}str;

#define CHUNKSIZE 20

typedef struct Chunk
{
	char ch[CHUNKSIZE];                 //存放一个块中的字符
	struct Chunk *next;                    //指向下一个块
}Chunk;

typedef struct
{
	Chunk *head, *tail;                    //串的头指针和尾指针
	int length;                                 //串的当前长度
}LStr;                                           //字符串的块链结构

int main()
{
	
	return 0;
}
