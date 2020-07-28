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
int GetLength(pNode *p);			//求单链表的表长(数据元素个数)
Datatype GetElem(pNode *p, int i);            //获取线性表中第i个位置的元素
int LocateList(pNode *p, Datatype x);        //根据指定数据元素获取该元素位置
void InsertList(pNode *p, int i, Datatype x);           //在第i个结点前插入新结点
void DeleteList(pNode *p, int i);                       //删除第i个结点
void CreateList(pNode *p, Datatype x);                 //头插法
void TailList(pNode *p, Datatype x);                     //尾插法
void PrintList(pNode *p);                                   //打印链表


int main()
{
	pNode List;
	InitList(&List);
	CreateList(&List, 55);
	CreateList(&List, 44);
	CreateList(&List, 33);
	CreateList(&List, 22);
	CreateList(&List, 11);
	PrintList(&List);
	TailList(&List, 66);
	TailList(&List, 77);
	TailList(&List, 88);
	TailList(&List, 99);
	PrintList(&List);
	DeleteList(&List, 5);
	PrintList(&List);
	InsertList(&List, 5, 55);
	PrintList(&List);
	printf("55是链表中的第%d个元素!\n", LocateList(&List, 55));
	printf("第六个元素是: %d\n", GetElem(&List, 6));
	printf("链表的表长为: %d\n", GetLength(&List));
	ClearList(&List);
	printf("链表的表长为: %d\n", GetLength(&List));
	DestroyList(&List);
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

int GetLength(pNode *p)			//求单链表的表长(数据元素个数)
{
	int i = 0;
	pNode pL = (*p)->next;        //pL指向第一个结点
	while (pL != NULL)                 //遍历单链表，统计结点数
	{
		i++;
		pL = pL->next;
	}
	return i;
}

Datatype GetElem(pNode *p, int i)            //获取线性表中第i个位置的元素
{
	pNode pL = (*p)->next;
	int j = 1;
	if (i<1 || i>GetLength(p))                //判断输入位置是否合理
	{
		printf("输入的位置不合理!\n");
		return 0;
	}
	if (IsEmpty(p))                                     //判断链表是否为空
	{
		printf("链表为空!\n");
		return 0;
	}
	while (j < i)                 //向后扫描直到p指向第i个元素
	{
		pL = pL->next;
		j++;
	}
	return pL->data;
}

int LocateList(pNode *p, Datatype x)        //根据指定数据元素获取该元素位置
{
	pNode pL = (*p)->next;
	int j = 1;
	if (IsEmpty(p))                            //判断链表是否为空
	{
		printf("链表为空!\n");
		return 0;
	}
	while ((pL->data!=x)&&(pL!=NULL))           
	{
		j++;
		pL = pL->next;
	}
	if (pL == NULL)                       //查找完链表仍未找到该元素则返回0
	{
		printf("该链表没有该元素!\n");
		return 0;
	}
	else
		return j;
}

void InsertList(pNode *p, int i, Datatype x)           //在第i个结点前插入新结点
{
	pNode pnode;
	pNode pL = (*p);
	int j = 1;
	if (i < 1 || i > GetLength(p))                      //判断输入位置是否合理
	{
		printf("输入位置不合理!\n");
		return;
	}
	pnode = (pNode)malloc(sizeof(Node));        
	pnode->data = x;                            //生成一个数据域为x的新结点pnode
	while (j < i)                                   //定位到第i-1个结点
	{ 
		pL = pL->next; 
		j++;
	}
	pnode->next = pL->next;               //新结点的指针域指向第i个结点
	pL->next = pnode;                         //第i-1个结点的指针域指向新结点
}

void DeleteList(pNode *p, int i)                       //删除第i个结点
{
	pNode pL = (*p);
	pNode qL;
	int j = 1;
	if (IsEmpty(p))                              //判断链表是否为空
	{
		printf("链表为空!\n");
		return;
	}
	if (i<1 || i>GetLength(p))            //判断输入位置是否合理
	{
		printf("输入位置不合法!\n");
		return;
	}
	while (j < i)                          //定位到第i-1个结点
	{
		pL = pL->next;
		j++;
	}
	qL = pL->next;                       //保存第i个结点的地址
	pL->next = pL->next->next;             //让第i-1个结点的指针域指向第i+1个结点
	free(qL);								//释放第i个结点的空间
}

void CreateList(pNode *p, Datatype x)                  //头插法
{
	pNode pnode;
	pnode = (pNode)malloc(sizeof(Node));      
	pnode->data = x;                                             //生成指针域为x的新结点
	pnode->next = (*p)->next;                             //将新结点的指针域指向头结点指针域所指向的结点
	(*p)->next = pnode;                                          //将头结点指针域指向新结点
}

void TailList(pNode *p, Datatype x)                     //尾插法
{
	pNode pnode;
	pNode pL = (*p);
	pnode = (pNode)malloc(sizeof(Node));
	pnode->data = x;
	pnode->next = NULL;                                 //生成指针域为NULL，数据域为x的新结点
	while (pL->next != NULL)
	{
		pL = pL->next;	                                 //将指针定位到链表的最后一个元素
	}
	pL->next = pnode;                                  //将链表的最后一个元素的指针域指向新结点
}

void PrintList(pNode *p)                    //打印链表
{
	pNode pL = (*p);
	while (pL->next != NULL)
	{
		printf("%d ", pL->next->data);
		pL = pL->next;
	}
	putchar('\n');
}