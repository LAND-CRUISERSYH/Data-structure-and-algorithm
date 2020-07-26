#include<stdio.h>
#include<stdlib.h>                //malloc()、free()函数原型

#define LIST_SIZE 20           //顺序表中可存放元素个数

typedef int Datatype;

typedef struct {
	Datatype *pL;
	int length;                    //顺序表元素个数(表长)
}SqList;

void InitList(SqList *p);              //初始化顺序表


int main()
{
	//SqList L;                   //创建一个顺序表
	printf("hello world");
	return 0; 
}

void InitList(SqList *p)
{
	p->pL = (Datatype*)malloc(LIST_SIZE * sizeof(Datatype));    //动态分配内存
	if (p->pL == NULL)
		exit(1);                               //内存分配失败
	p->length = 0;                  //表长为0；
}
