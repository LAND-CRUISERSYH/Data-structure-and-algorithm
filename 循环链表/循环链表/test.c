#include<stdio.h>
#include<stdlib.h>                   //提供malloc()、free()函数原型

typedef int Datatype;

typedef struct Node                              //声明结点的类型和指向结点的指针类型
{
	Datatype data;									//结点的数据域
	struct Node *next;							//结点的指针域
}Node,*pNode;									//pNode为指向结点的指针类型


void InitList(pNode *p);                               //初始化链表
int IsEmpty(pNode *p);                               //判断链表是否为空
void Destroy(pNode *p);								//销毁链表
void Clear(pNode *p);                                  //清空链表
int GetLength(pNode *p);                            //求表长
void CreateList(pNode *p, Datatype x);            //头插
void TailList(pNode *p, Datatype x);            //尾插
void PrintList(pNode *p);                               //打印链表
pNode Tail_Pointer(pNode *p);                      //查找尾指针
void MergeList(pNode *p1, pNode *p2);           //合并两个循环链表

int main()
{
	pNode LA;
	pNode LB;
	pNode LC;
	pNode LD;
	InitList(&LA);
	InitList(&LB);
	CreateList(&LA, 55);
	CreateList(&LA, 44);
	CreateList(&LA, 33);
	CreateList(&LA, 22);
	CreateList(&LA, 11);
	PrintList(&LA);
	printf("LA表的长度为: %d\n", GetLength(&LA));
	TailList(&LB, 66);
	TailList(&LB, 77);
	TailList(&LB, 88);
	TailList(&LB, 99);
	PrintList(&LB);
	printf("LB表的长度为: %d\n", GetLength(&LB));
	LC = Tail_Pointer(&LA);
	LD = Tail_Pointer(&LB);
	MergeList(&LC, &LD);
	PrintList(&LA);
	printf("LA表的长度为: %d\n", GetLength(&LA));
	Destroy(&LA);
	return 0;
}

void InitList(pNode *p)                               //初始化链表
{
	*p = (pNode)malloc(sizeof(Node));                   //用头指针指向头结点
	(*p)->next = (*p);											//头结点的指针域指向头结点
}

int IsEmpty(pNode *p)                               //判断链表是否为空
{
	if ((*p)->next == (*p))                          //判断头结点指针域是否指向头结点
		return 1;										//为空返回1
	return 0;											//不为空返回0
}

void Destroy(pNode *p)							//销毁链表
{
	pNode pL = (*p)->next;                       //将指针pL指向首元结点
	(*p)->next = NULL;                             //将头结点的指针域置空
	*p = pL;                                              //指向首元结点
	while ((*p) != NULL)
	{
		pL = *p;
		*p = (*p)->next;               
		free(pL);                                          //依次释放结点(最后释放头结点)
	}
}

void Clear(pNode *p)                                  //清空链表
{
	pNode pL = (*p)->next;                          //将指针指向首元结点
	pNode qL;
	while (pL != (*p))
	{
		qL = pL;
		pL = pL->next;
		free(qL);                                            //依次释放结点
	}
	(*p)->next = (*p);                                //将头结点的指针域指向自己
}

int GetLength(pNode *p)                            //求表长
{
	int i = 0;
	pNode pL = (*p)->next;                          //将pL指向首元结点
	while (pL!= (*p))                                      //遍历链表，统计元素个数
	{
		i++;
		pL = pL->next;
	}
	return i;
}

void CreateList(pNode *p, Datatype x)            //头插
{
	pNode pnode;
	pnode = (pNode)malloc(sizeof(Node));
	pnode->data = x;                                            //创建一个数据域为x的新结点
	pnode->next = (*p)->next;                              //新结点的指针域指向头结点指针域指向的结点
	(*p)->next = pnode;                                    //头结点指针域指向新结点
}

void PrintList(pNode *p)                               //打印链表
{
	pNode pL = (*p)->next;
	while (pL != (*p))
	{
		printf("%d ", pL->data);
		pL = pL->next;
	}
	printf("\n");
}

void TailList(pNode *p, Datatype x)            //尾插
{
	pNode pnode;
	pNode pL = (*p);
	pnode = (pNode)malloc(sizeof(Node)); 
	pnode->data = x;                                    //创建一个数据域为x的新结点
	while (pL->next!=(*p))
	{
		pL = pL->next;                                    //定位到链表的最后一个结点
	}
	pL->next = pnode;                            //最后一个结点的指针域指向新结点
	pnode->next = (*p);                            //新结点的指针域指向头结点
}

pNode Tail_Pointer(pNode *p)                      //查找尾指针
{
	pNode pL = (*p);
	while (pL->next!= (*p))
	{
		pL = pL->next;
	}
	return pL;
}

void MergeList(pNode *p1, pNode *p2)           //合并两个循环链表
{
	pNode pL = (*p1)->next;                                             //保存第一条链表的头结点
	(*p1)->next = (*p2)->next->next;                      //将第一条链表末尾结点的指针域指向第二条链表的首元结点
	free((*p2)->next);                                      //释放第二条链表的头结点
	(*p2)->next = pL;                                     //将第二条链表末尾结点的指针域指向第一条链表的头结点
}