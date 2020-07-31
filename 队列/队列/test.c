//#include<stdio.h>
//#include<stdlib.h>
//
//#define SIZE 10                              //最大队列长度
//
//typedef int Datatype;
//typedef struct
//{
//	Datatype *arr;                         //初始化的动态分配存储空间
//	int front;									//队头元素的下标
//	int rear;									//指向队列尾元素的下一个位置
//}SqQueue;
//
//void InitQueue(SqQueue *p);                      //队列的初始化
//int GetLength(SqQueue *p);                    //求队列长度
//void EnQueue(SqQueue *p, Datatype x);            //入队
//Datatype OutQueue(SqQueue *p);                     //出队
//void DestoryQueue(SqQueue *p);                    //销毁队列
//
//int main()
//{
//	SqQueue Q;
//	InitQueue(&Q);
//	EnQueue(&Q, 1);
//	EnQueue(&Q, 2);
//	EnQueue(&Q, 3);
//	EnQueue(&Q, 4);
//	EnQueue(&Q, 5);
//	printf("队列长度为: %d\n", GetLength(&Q));
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", OutQueue(&Q));
//	}
//	putchar('\n');
//	DestoryQueue(&Q);
//}
//
//void InitQueue(SqQueue *p)                      //队列的初始化
//{
//	p->arr = (Datatype*)malloc(SIZE* sizeof(Datatype));                  //分配数组空间
//	if (!p->arr)                                                    //判断分配是否成功
//	{
//		printf("内存分配失败!\n");
//		return;
//	}
//	p->front =p->rear= 0;                          //队头队尾下标置0，队列为空
//}
//
//int GetLength(SqQueue *p)                    //求队列长度
//{
//	return ((p->rear - p->front + SIZE) % SIZE);               //一定要取余(不取余队列为空时计算出错)
//}
//
//void EnQueue(SqQueue *p, Datatype x)            //入队
//{
//	if ((p->rear + 1) % SIZE == p->front)               //判断是否队满
//	{
//		printf("队满!\n");
//		return;
//	}
//	p->arr[p->rear] = x;                                   //将数据元素放入rear下标位置
//	p->rear = (p->rear + 1) % SIZE;                    //改变rear下标
//}
//
//Datatype OutQueue(SqQueue *p)                     //出队
//{
//	Datatype temp;
//	if (p->front == p->rear)                              //判断是否队空
//	{
//		printf("队空!\n");
//		return 0;
//	}
//	temp = p->arr[p->front];                         //获取队头元素
//	p->front = (p->front + 1) % SIZE;           //修改队头下标
//	return temp;                                           //返回队头数据
//} 
//
//void DestoryQueue(SqQueue *p)                    //销毁队列
//{
//	if (p->arr)
//		free(p->arr);                    
//}
#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;
typedef struct Qnode
{
	Datatype data;                             //结点数据域
	struct Qnode *next;                         //结点指针域
}Qnode,*pQnode;

typedef struct LinkQueue
{
	pQnode front;                             //队头指针
	pQnode rear;                             //队尾指针
}LinkQueue;

void InitQueue(LinkQueue *p);              //初始化链队列
void Destroy(LinkQueue *p);                  //销毁链队列
void EnQueue(LinkQueue *p, Datatype x);    //入队
void OutQueue(LinkQueue *p);                      //出队
Datatype GetHead(LinkQueue *p);                   //取队头元素
int GetLength(LinkQueue *p);                       //求队列长度

int main()
{
	LinkQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, 2);
	EnQueue(&Q, 6);
	EnQueue(&Q, 7);
	EnQueue(&Q, 8);
	EnQueue(&Q, 9);
	printf("队列长度为: %d\n", GetLength(&Q));
	printf("队头元素为: %d\n", GetHead(&Q));
	OutQueue(&Q);
	OutQueue(&Q);
	printf("队列长度为: %d\n", GetLength(&Q));
	printf("队头元素为: %d\n", GetHead(&Q));
	Destroy(&Q);
	return 0;
}

void InitQueue(LinkQueue *p)              //初始化链队列
{
	p->front = p->rear = (pQnode)malloc(sizeof(Qnode));   //分配存储空间
	if (!p->front)                                      //内存是否分配成功
	{
		printf("内存分配失败!\n");
		return;
	}
	p->front->next = NULL;               //头结点指针域置空
}

void Destroy(LinkQueue *p)                  //销毁链队列
{
	pQnode pL;
	while (p->front)
	{
		pL = p->front->next;
		free(p->front);                       //依次释放所有结点
		p->front = pL;
	}
}

void EnQueue(LinkQueue *p, Datatype x)    //入队
{
	pQnode temp;
	temp = (pQnode)malloc(sizeof(Qnode));
	if (!temp)                              //内存是否分配成功
	{
		printf("内存分配失败!\n");
		return;
	}
	temp->data = x;                      //生成数据域为x，指针域为NULL的新结点
	temp->next = NULL;
	p->rear->next = temp;               //将新结点链接在队尾
	p->rear = temp;                          //队尾指针指向队尾
}

void OutQueue(LinkQueue *p)                      //出队
{
	pQnode temp;
	if (p->front == p->rear)
	{
		printf("队空!\n");
		return;                            
	} 
	temp = p->front->next;                              //指向队头元素
	p->front->next = temp->next;            //将队头元素的next链接到头结点
	if (p->rear == temp)
		p->rear = p->front;                           //如果队中仅有一个元素
	free(temp);                                       //释放队头元素
}

Datatype GetHead(LinkQueue *p)                   //取队头元素
{
	if (p->front == p->rear)                               //反对是否队空
	{
		printf("队空!\n");
		return 0;
	}
	return p->front->next->data;                      //返回队头元素
}

int GetLength(LinkQueue *p)                       //求队列长度
{
	pQnode pL = p->front->next;
	int i = 0;
	while (pL != NULL)
	{
		i++;
		pL = pL->next;
	}
	return i;
}