#include<stdio.h>
#include<stdlib.h>

#define SIZE 10                              //最大队列长度

typedef int Datatype;
typedef struct
{
	Datatype *arr;                         //初始化的动态分配存储空间
	int front;									//队头元素的下标
	int rear;									//队尾元素的下标
}SqQueue;