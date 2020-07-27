#include<stdio.h>
#include<stdlib.h>                //malloc()、free()函数原型

#define LIST_SIZE 20           //顺序表中可存放元素个数

typedef int Datatype;

typedef struct {
	Datatype *pL;
	int length;                    //顺序表元素个数(表长)
}SqList;

void InitList(SqList *p);              //初始化顺序表
void DestroyList(SqList * p);           //销毁顺序表
void ClearList(SqList * p);           //清空顺序表
int GetLength(SqList * p);           //求顺序表长度
int IsEmpty(SqList *p);              //判断顺序表是否为空
Datatype GetElem(SqList *p, int i);        //获取第i个位置的数据元素
int LocateElem(SqList *p, Datatype x);     //查找顺序表中某一数据元素的位置
void InsertList(SqList *p, int i, Datatype x);       //顺序表中插入某个元素 
void DeleteList(SqList *p, int i);       //顺序表中删除某个元素 
void PrintList(SqList *p);                 //打印顺序表



int main()
{

	SqList L;                   //创建一个顺序表
	InitList(&L);
	InsertList(&L, 1, 1);
	InsertList(&L, 2, 2);
	InsertList(&L, 3, 3);
	InsertList(&L, 4, 5);
	PrintList(&L);
	printf("顺序表元素个数: %d\n", GetLength(&L));
	InsertList(&L, 4, 4);
	PrintList(&L);
	printf("顺序表元素个数: %d\n", GetLength(&L));
	printf("4在顺序表中的位置: %d\n", LocateElem(&L, 4));
	printf("第2个元素为: %d\n", GetElem(&L, 2));
	ClearList(&L);
	printf("顺序表元素个数: %d\n", GetLength(&L));
	DestroyList(&L);
	return 0; 
}

void InitList(SqList *p)
{
	p->pL = (Datatype*)malloc(LIST_SIZE * sizeof(Datatype));    //动态分配内存
	if (p->pL == NULL)
	{
		printf("内存分配失败!\n");
		return;                               //内存分配失败
	}
	p->length = 0;                  //表长为0；
}

void DestroyList(SqList * p)           //销毁顺序表
{
	if (p->pL)
		free(p->pL);					//释放存储空间
}

void ClearList(SqList * p)           //清空顺序表
{
	p->length = 0;                   //将顺序表的长度置为0
}

int GetLength(SqList * p)           //求顺序表长度
{
	return p->length;
}

int IsEmpty(SqList *p)              //判断顺序表是否为空
{
	if (p->length == 0)
		return 1;               //为空返回1
	else
		return 0;              //不为空返回0
}

Datatype GetElem(SqList *p, int i)        //获取第i个位置的数据元素
{
	if (IsEmpty(p))           //判断顺序表是否为空
	{
		printf("顺序表为空!\n");
		return  0;
	}
	else if (i<1 || i>p->length)       //判断输入位置是否合理
	{
		printf("输入的位置不合理!\n");
		return 0;
	}
	else											//返回相应位置的数据元素
		return p->pL[i - 1];
}

int LocateElem(SqList *p, Datatype x)     //查找顺序表中某一数据元素的位置
{
	if (IsEmpty(p))                                 //判断顺序表是否为空
	{
		printf("顺序表为空!\n");
		return -1;
	}
	for (int i = 0; i < p->length; i++)         
	{
		if (x == p->pL[i])
			return i + 1;                         //查找成功，返回元素在顺序表中的位置
	} 
	return 0;                                       //查找失败，返回0
}

void InsertList(SqList *p, int i, Datatype x)       //顺序表中插入某个元素
{
	if (i<1 || i>p->length + 1)                       //判断插入位置是否合法
	{
		printf("插入的位置不合法!\n");      
		return;
	}
	if (p->length == LIST_SIZE)                   //判断顺序表是否已满
	{
		printf("顺序表已满!\n");
		return;
	}
	else
	{
		for (int j = p->length - 1; j >= i-1; j--)        
		{
			p->pL[j + 1] = p->pL[j];					  //将元素依次向后移动
		}
		p->pL[i - 1] = x;                                   //将x插入到下标为i-1的位置(即顺序表的第i个位置)
		p->length++;                                      //顺序表的元素个数+ 1
	}
}

void DeleteList(SqList *p, int i)       //顺序表中删除某个元素 
{
	if (IsEmpty(p))                            //判断顺序表是否为空
	{
		printf("顺序表为空!\n");
		return;
	}
	if (i<1 || i>p->length)                //判断删除位置是否合法
	{
		printf("删除的位置不合法!\n");
		return;
	}
	else
	{
		for (int j = i ; j <= p->length-1; j++)          
			p->pL[j-1] = p->pL[j];				//将元素依次向前移动
		p->length--;									//顺序表的元素个数-1
	}
}

void PrintList(SqList *p)                 //打印顺序表
{
	for (int i = 0; i < p->length; i++)
		printf("%d ", p->pL[i]);
	printf("\n");
}
