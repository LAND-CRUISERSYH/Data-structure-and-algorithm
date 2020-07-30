//#include<stdio.h>
//#include<stdlib.h>
//
//#define SIZE 10
//
//typedef int Datatype;
//typedef struct Stack
//{
//	Datatype *base;                         //栈底指针
//	Datatype *top;							//栈顶指针
//	int stacksize;							//栈可用的最大容量
//}SqStack;
//
//void InitStack(SqStack *p);                  //顺序栈的初始化
//int IsEmpty(SqStack *p);                     //判断栈是否为空
//int GetLength(SqStack *p);                 //求顺序栈长度
//void ClearStack(SqStack *p);             //清空顺序栈
//void DestroyStack(SqStack *p);        //销毁顺序栈
//void PushStack(SqStack *p, Datatype x);          //入栈
//Datatype PopStack(SqStack *p);                      //出栈
//void PrintStack(SqStack *p);                       //打印
//
//int main()
//{
//	SqStack S;
//	InitStack(&S);
//	PushStack(&S, 1);
//	PushStack(&S, 2);
//	PushStack(&S, 3);
//	PushStack(&S, 4);
//	PushStack(&S, 5);
//	printf("栈长为: %d\n", GetLength(&S));
//	PrintStack(&S);
//	while (!IsEmpty(&S))
//	{
//		printf("%d ", PopStack(&S));
//	}
//	putchar('\n');
//	DestroyStack(&S);
//	return 0;
//}
//
//void InitStack(SqStack *p)                  //顺序栈的初始化
//{
//	p->base = (Datatype*)malloc(SIZE * sizeof(Datatype));
//	if (!p->base)                                          
//	{
//		printf("内存分配失败!\n");                //存储分配失败
//		return;
//	}
//	p->top = p->base;                         //栈顶指针等于栈底指针
//	p->stacksize = SIZE;
//}
//
//int IsEmpty(SqStack *p)                     //判断栈是否为空
//{
//	if (p->base == p->top)           //若栈为空返回1
//		return 1;
//	return 0;									//不为空返回0
//}
//
//int GetLength(SqStack *p)                 //求顺序栈长度
//{
//	return p->top - p->base;             //栈顶指针和栈底指针的差值
//}
//
//void ClearStack(SqStack *p)             //清空顺序栈
//{
//	if (p->base)                                   //如果栈存在，将栈顶指针指向栈底
//		p->top = p->base; 	
//}
//
//void DestroyStack(SqStack *p)        //销毁顺序栈
//{
//	if (p->base)                                     //判断栈是否存在
//	{ 
//		free(p->base);                          //销毁顺序栈
//		p->stacksize = 0;
//		p->base = p->top = NULL;
//	}
//}
//
//void PushStack(SqStack *p, Datatype x)          //入栈
//{
//	if (p->top - p->base == p->stacksize)         //判断是否栈满
//	{
//		printf("栈满!\n");
//		return;
//	}
//	*(p->top) = x;                          //元素入栈
//	p->top++;                             //栈顶指针+1
//}  
//
//Datatype PopStack(SqStack *p)                      //出栈
//{
//	if (IsEmpty(p))                      //判断是否栈空
//	{
//		printf("栈空!\n");
//		return 0;
//	}
//	p->top--;                            //栈顶元素-1
//	return *(p->top);                      //返回栈顶元素
//}
//
//void PrintStack(SqStack *p)                       //打印
//{
//	for (int i = 0; i < p->top - p->base; i++)
//	{
//		printf("%d ", p->base[i]);
//	}
//	putchar('\n');
//}
#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;
typedef struct Node
{
	Datatype data;
	struct Node *next;
}Node,*pNode;

void InitStack(pNode *p);                    //链栈的初始化
int IsEmpty(pNode *p);                       //判断链栈是否为空
void PushStack(pNode *p, Datatype x);          //入栈
Datatype PopStack(pNode *p);                 //出栈
void Destroy(pNode *p);                         //销毁链栈
int GetLength(pNode *p);                         //求链栈长度

int main()
{
	pNode S;
	InitStack(&S);
	PushStack(&S, 6);
	PushStack(&S, 7);
	PushStack(&S, 8);
	PushStack(&S, 9);
	PushStack(&S, 10);
	int num = GetLength(&S);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", PopStack(&S));
	}
	putchar('\n');
	Destroy(&S);
	return 0;
}

void InitStack(pNode *p)                    //链栈的初始化
{
	*p = NULL;                                      //头指针指向空
}

int IsEmpty(pNode *p)                       //判断链栈是否为空
{
	if (*p == NULL)                               //为空返回1
		return 1; 
	return 0;                                        //不为空返回0
}

void PushStack(pNode *p, Datatype x)          //入栈
{
	pNode pnode = (pNode)malloc(sizeof(Node));          
	pnode->data = x;                              //生成数据域为x的新结点
	pnode->next = (*p);                      //将新结点插入栈顶
	(*p) = pnode;                               //修改栈顶指针
}

Datatype PopStack(pNode *p)                 //出栈
{
	pNode pL;                              
	Datatype temp;                        //暂存出栈的元素数据
	if (IsEmpty(p))                           //判断栈是否为空
	{
		printf("栈空!\n");
		return 0;
	}
	pL = *p;
	(*p) = (*p)->next;                   //将栈顶指针后移
	temp = pL->data;                  
	free(pL);                                  //释放出栈的元素内存
	return temp;                             //返回结点数据
}

void Destroy(pNode *p)                         //销毁链栈
{
	pNode pL;
	while ((*p) != NULL)
	{
		pL = *p;
		(*p) = (*p)->next;        
		free(pL);                                     //依次释放结点
	}
}

int GetLength(pNode *p)                         //求链栈长度
{
	int i = 0;
	pNode pL = *p;
	while (pL != NULL)                     
	{
		i++;
		pL = pL->next;
	}
	return i;
}
