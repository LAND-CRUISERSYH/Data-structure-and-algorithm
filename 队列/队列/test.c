#include<stdio.h>
#include<stdlib.h>

#define SIZE 10                              //最大队列长度

typedef int Datatype;
typedef struct
{
	Datatype *arr;                         //初始化的动态分配存储空间
	int front;									//队头元素的下标
	int rear;									//指向队列尾元素的下一个位置
}SqQueue;

void InitQueue(SqQueue *p);                      //队列的初始化
int GetLength(SqQueue *p);                    //求队列长度
void EnQueue(SqQueue *p, Datatype x);            //入队
Datatype OutQueue(SqQueue *p);                     //出队
void DestoryQueue(SqQueue *p);                    //销毁队列

int main()
{
	SqQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);
	EnQueue(&Q, 4);
	EnQueue(&Q, 5);
	printf("队列长度为: %d\n", GetLength(&Q));
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", OutQueue(&Q));
	}
	putchar('\n');
	DestoryQueue(&Q);
}

void InitQueue(SqQueue *p)                      //队列的初始化
{
	p->arr = (Datatype*)malloc(SIZE* sizeof(Datatype));                  //分配数组空间
	if (!p->arr)                                                    //判断分配是否成功
	{
		printf("内存分配失败!\n");
		return;
	}
	p->front =p->rear= 0;                          //队头队尾下标置0，队列为空
}

int GetLength(SqQueue *p)                    //求队列长度
{
	return ((p->rear - p->front + SIZE) % SIZE);               //一定要取余(不取余队列为空时计算出错)
}

void EnQueue(SqQueue *p, Datatype x)            //入队
{
	if ((p->rear + 1) % SIZE == p->front)               //判断是否队满
	{
		printf("队满!\n");
		return;
	}
	p->arr[p->rear] = x;                                   //将数据元素放入rear下标位置
	p->rear = (p->rear + 1) % SIZE;                    //改变rear下标
}

Datatype OutQueue(SqQueue *p)                     //出队
{
	Datatype temp;
	if (p->front == p->rear)                              //判断是否队空
	{
		printf("队空!\n");
		return 0;
	}
	temp = p->arr[p->front];                         //获取队头元素
	p->front = (p->front + 1) % SIZE;           //修改队头下标
	return temp;                                           //返回队头数据
} 

void DestoryQueue(SqQueue *p)                    //销毁队列
{
	if (p->arr)
		free(p->arr);                    
}