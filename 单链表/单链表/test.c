#include<stdio.h>
#include<stdlib.h>               //提供malloc()、free()函数原型

typedef int Datatype;

typedef struct Node              //声明结点类型和指向结点的指针类型
{
	Datatype data;					//结点的数据域
	struct  Node *next;			//结点的指针域
}Node,*pNode;					//pNode为指向结构体Node的指针类型

void InitList(pNode *p);             //单链表的初始化
int IsEmpty(pNode *p);              //判断链表是否为空 
void DestroyList(pNode *p);        //销毁单链表
void ClearList(pNode *p);           //清空链表


int main()
{
	return 0;
}

void InitList(pNode *p)             //单链表的初始化
{   
	*p = (pNode)malloc(sizeof(Node));             //用头指针指向头结点
	(*p)->next = NULL;                    //头结点的指针域置空
}

int IsEmpty(pNode *p)              //判断链表是否为空
{
	if ((*p)->next == NULL)               //判断头结点指针域是否为空
		return 1;								//为空返回1
	return 0;									//不为空返回0
}

void DestroyList(pNode *p)        //销毁单链表
{
	pNode pL;
	while ((*p) != NULL)
	{
		pL = *p;
		*p = (*p)->next;            
		free(pL);                            //依次释放结点
	}
}

void ClearList(pNode *p)           //清空链表
{
	pNode pL = (*p)->next;
	pNode qL;
	while (pL)         
	{
		qL = pL->next;                              
		free(pL);												//依次释放结点
		pL = qL;										
	}
	(*p)->next = NULL;                  //将头结点指针域设置为空
}