#include<stdio.h>
#include<stdlib.h>

//typedef int Datatype;
//
//typedef struct Node
//{
//	Datatype data;
//	struct Node *front, *next;                                        //前驱指针域和后继指针域
//}Node,*pNode; 

//void InsertList(pNode *p, int i, Datatype x);                    //双向链表的插入
//void DeleteList(pNode *p, int i);                                   //双向链表的删除

//int main()
//{
//	return 0;
//}

//void InsertList(pNode *p, int i, Datatype x)                    //双向链表的插入
//{
//	int length = 0;                                                           //计算表长
//	pNode pL = (*p);
//	pNode qL = (*p);                                                         //定位到第i个结点
//	int j = 0;
//	pNode pnode;
//	pnode = (pNode)malloc(sizeof(Node));
//	pnode->data = x;                                                   //生成数据域为x的新结点
//	if ((*p)->next == NULL)                                               //判断链表是否为空
//	{
//		printf("链表为空!\n");
//		return;
//	}
//	while (pL->next != NULL)
//	{
//		length++;                                                             //依次迭代计数
//		pL = pL->next;             
//	}
//	if (i<1 || i>length)                                                  //判断输入位置是否合理
//	{
//		printf("输入位置不合理!\n");
//		return;
//	}
//	while (j < i)
//	{
//		qL = qL->next;
//		j++;
//	}             
//	pnode->front = qL->front;
//	qL->front->next = pnode;
//	pnode->next = qL;
//	qL->front = pnode;
//}

//void DeleteList(pNode *p, int i)                                   //双向链表的删除
//{
//	int length = 0;                                                           //计算表长
//	pNode pL = (*p);
//	pNode qL = (*p);                                                         //定位到第i个结点
//	int j = 0;
//	if ((*p)->next == NULL)                                               //判断链表是否为空
//	{
//		printf("链表为空!\n");
//		return;
//	}
//	while (pL->next != NULL)
//	{
//		length++;                                                             //依次迭代计数
//		pL = pL->next;
//	}
//	if (i<1 || i>length)                                                  //判断输入位置是否合理
//	{
//		printf("输入位置不合理!\n");
//		return;
//	}
//	while (j < i)
//	{
//		qL = qL->next;
//		j++;
//	}
//	qL->front->next = qL->next;
//	qL->next->front = qL->front;
//	free(qL);
//}