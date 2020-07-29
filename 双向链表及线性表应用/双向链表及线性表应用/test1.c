//#include<stdio.h>
//#include<stdlib.h>
//
//#define SIZE 10
//
//typedef int Datatype;
//
//typedef struct Node
//{
//	Datatype *arr;
//	int length;
//}Node;
//
//void InitList(Node *p);                                //初始化顺序表
//void PrintList(Node *p);                             //打印顺序表
//void InsertList(Node *p, int i, Datatype x);               //插入元素
//void DestroyList(Node *p);                                 //销毁顺序表
//void MergeList(Node *p1, Node *p2);               //两个顺序表合并(求并集)
//void Merge_List(Node *p1, Node *p2, Node *p3);     //有序表的合并
//
//int main()
//{
//	/*Node LA;
//	Node LB;
//	InitList(&LA);
//	InitList(&LB);
//	InsertList(&LA, 1, 7);
//	InsertList(&LA, 2, 5);
//	InsertList(&LA, 3, 3);
//	InsertList(&LA, 4, 11);
//	PrintList(&LA);
//	InsertList(&LB, 1, 2);
//	InsertList(&LB, 2,6);
//	InsertList(&LB, 3, 3);
//	PrintList(&LB);
//	MergeList(&LA, &LB);
//	PrintList(&LA);
//	DestroyList(&LA);
//	DestroyList(&LB);*/
//	Node LA, LB, LC;
//	InitList(&LA);
//	InitList(&LB);
//	InsertList(&LA, 1, 1);
//	InsertList(&LA, 2, 7);
//	InsertList(&LA, 3, 8);
//	PrintList(&LA);
//	InsertList(&LB, 1, 2);
//	InsertList(&LB, 2, 4);
//	InsertList(&LB, 3, 6);
//	InsertList(&LB, 4, 8);
//	InsertList(&LB, 5, 10);
//	InsertList(&LB, 6, 11);
//	PrintList(&LB);
//	Merge_List(&LA, &LB, &LC);
//	PrintList(&LC);
//	DestroyList(&LA);
//	DestroyList(&LB);
//	DestroyList(&LC);
//	return 0;
//}
//
//void InitList(Node *p)                                //初始化顺序表
//{
//	p->arr = (Datatype*)malloc(SIZE * sizeof(Datatype));
//	if (p->arr == NULL)
//	{
//		printf("内存分配失败!\n");
//		return;
//	}
//	p->length = 0;
//}
//
//void PrintList(Node *p)                             //打印顺序表
//{
//	for (int i = 0; i < p->length; i++)
//	{
//		printf("%d ", p->arr[i]);
//	}
//	putchar('\n');
//}
//
//void InsertList(Node *p, int i, Datatype x)               //插入元素
//{
//	if(i<1||i>p->length+1)
//	{
//		printf("插入位置不合理!\n");
//		return;
//	}
//	if (p->length == SIZE)
//	{
//		printf("顺序表已满!\n");
//		return;
//	}
//	else
//	{
//		for (int j = p->length - 1; j >= i - 1; j--)
//		{
//			p->arr[j + 1] = p->arr[j];
//		}
//		p->arr[i - 1] = x;
//		p->length++;
//	}
//}
//
//void DestroyList(Node *p)                                 //销毁顺序表
//{
//	free(p->arr);
//}
//
//void MergeList(Node *p1, Node *p2)               //两个顺序表合并(求并集)
//{
//	int flag = 0;
//	int length_A = p1->length;
//	int length_B = p2->length;
//	for (int i = 0; i < p2->length; i++)
//	{
//		flag = 0;
//		for (int j = 0; j < p1->length; j++)
//		{
//			if (p1->arr[j] == p2->arr[i])
//				flag = 1;
//		}
//		if (flag == 0)
//		{
//			InsertList(p1, ++length_A, p2->arr[i]);
//		}
//	}
//}
//
//void Merge_List(Node *p1, Node *p2, Node *p3)     //有序表的合并
//{
//	int *pa = p1->arr;                                      //指向第一个顺序表的第一个元素
//	int *pb = p2->arr;                                    //指向第二个顺序表的第一个元素
//	int *pa_last = (p1->arr) + p1->length - 1;         //指向第一个顺序表的表尾元素
//	int *pb_last = (p2->arr) + p2->length - 1;            //指向第二个顺序表的表尾元素
//	p3->length = p1->length + p2->length;                         
//	p3->arr = (Datatype*)malloc(p3->length*sizeof(Datatype));    //初始化最终顺序表
//	int *pc = p3->arr;                                             //指向最终顺序表的第一个元素
//	while (pa <= pa_last&&pb <= pb_last)            //第一个顺序表没判断完并且第二个顺序表没判断完
//	{
//		if ((*pa) <= (*pb))                                    //如果第一个顺序表的元素小于第二个顺序表的元素
//		{
//			*pc = *pa;                                         //将元素放入最终顺序表
//			pc++;                                                 //最终顺序表元素后移
//			pa++;                                          //第一个顺序表的元素指针后移
//		}
//		else                                        //如果第一个顺序表的元素大于第二个顺序表的元素
//		{
//			*pc = *pb;							//将元素放入最终顺序表
//			pc++;                                        //最终顺序表元素指针后移
//			pb++;                                       //第二个顺序表的元素指针后移
//		}
//	}
//	while (pa <= pa_last)                        //如果第二个顺序表判断完第一个顺序表没判断完
//	{
//		*pc = *pa;
//		pc++;
//		pa++;
//	}
//	while (pb <= pb_last)							 //如果第一个顺序表判断完第二个顺序表没判断完
//	{
//		*pc = *pb;
//		pc++;
//		pb++;
//	}
//}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;

typedef struct Node
{
	Datatype data;
	struct Node *next;
}Node,*pNode;

void InitList(pNode *p);                               //初始化链表
void PrintfList(pNode *p);                               //打印链表
void DestoryList(pNode *p);                             //销毁链表
void CreateList(pNode *p,Datatype x);                                   //头插
void TailList(pNode *p, Datatype x);                                   //尾插
void MergeList(pNode *p1, pNode *p2);                             //合并链表求并集
void Merge_List(pNode *p1, pNode *p2);                         //合并两个有序链表

int main()
{
	/*pNode LA, LB;
	InitList(&LA);
	InitList(&LB);
	CreateList(&LA, 11);
	CreateList(&LA, 3);
	CreateList(&LA, 5);
	CreateList(&LA, 7);
	PrintfList(&LA);
	TailList(&LB, 2);
	TailList(&LB, 6);
	TailList(&LB, 3);
	PrintfList(&LB);
	MergeList(&LA, &LB);
	PrintfList(&LA);
	DestoryList(&LA);
	DestoryList(&LB);*/
	pNode LA, LB;
	InitList(&LA);
	InitList(&LB);
	TailList(&LA, 1);
	TailList(&LA, 7);
	TailList(&LA, 8);
	PrintfList(&LA);
	CreateList(&LB, 11);
	CreateList(&LB, 10);
	CreateList(&LB, 8);
	CreateList(&LB, 6);
	CreateList(&LB, 4);
	CreateList(&LB, 2);
	PrintfList(&LB);
	Merge_List(&LA, &LB);
	PrintfList(&LA);
	DestoryList(&LA);
	return 0;
}

void InitList(pNode *p)                               //初始化链表
{
	*p = (pNode)malloc(sizeof(Node));
	(*p)->next = NULL;
}

void PrintfList(pNode *p)                               //打印链表
{
	pNode pL = (*p)->next;
	while (pL != NULL)
	{
		printf("%d ", pL->data);
		pL = pL->next;
	}
	putchar('\n');
}

void DestoryList(pNode *p)                             //销毁链表
{
	pNode pL;
	while ((*p) != NULL)
	{
		pL = *p;
		*p = (*p)->next;
		free(pL);
	}
}

void CreateList(pNode *p, Datatype x)                                   //头插
{
	pNode pnode;
	pnode = (pNode)malloc(sizeof(Node));
	pnode->data = x;
	pnode->next = (*p)->next;
	(*p)->next = pnode;
}
void TailList(pNode *p, Datatype x)                                   //尾插
{
	pNode pnode;
	pNode pL = (*p);
	pnode = (pNode)malloc(sizeof(Node));
	pnode->data = x;
	pnode->next = NULL;
	while (pL->next != NULL)
	{
		pL = pL->next;
	}
	pL->next = pnode;
}

void MergeList(pNode *p1, pNode *p2)                             //合并链表求并集
{
	pNode pL = (*p1)->next;
	pNode qL = (*p2)->next;
	int flag = 0;
	while (qL != NULL)
	{
		pL = (*p1)->next;
		while (pL != NULL)
		{
			if (pL->data == qL->data)
				flag = 1;
			pL = pL->next;
		}
		if (flag == 0)
		{
			TailList(p1, qL->data);
		}
		qL = qL->next;
	}
}

void Merge_List(pNode *p1, pNode *p2)                         //合并两个有序链表
{
	pNode pa = (*p1)->next;                                       //指向第一个链表的首元结点
	pNode pb = (*p2)->next;							         //指向第二个链表的首元结点
	pNode pc = (*p1);                                             //指向第一个链表的头结点
	while (pa&&pb)                                                //pa、pb不为空则进行判断，若有一个为空则退出循环
	{
		if ((pa->data) <= (pb->data))
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;                                 //若有一个链表被判断完，则将另一个链表的剩余部分链到pc->next;
	free(*p2);                                                      //释放第二个链表的头结点
}
