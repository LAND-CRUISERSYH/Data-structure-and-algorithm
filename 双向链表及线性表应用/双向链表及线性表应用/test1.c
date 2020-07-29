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
//void InitList(Node *p);                                //��ʼ��˳���
//void PrintList(Node *p);                             //��ӡ˳���
//void InsertList(Node *p, int i, Datatype x);               //����Ԫ��
//void DestroyList(Node *p);                                 //����˳���
//void MergeList(Node *p1, Node *p2);               //����˳���ϲ�(�󲢼�)
//void Merge_List(Node *p1, Node *p2, Node *p3);     //�����ĺϲ�
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
//void InitList(Node *p)                                //��ʼ��˳���
//{
//	p->arr = (Datatype*)malloc(SIZE * sizeof(Datatype));
//	if (p->arr == NULL)
//	{
//		printf("�ڴ����ʧ��!\n");
//		return;
//	}
//	p->length = 0;
//}
//
//void PrintList(Node *p)                             //��ӡ˳���
//{
//	for (int i = 0; i < p->length; i++)
//	{
//		printf("%d ", p->arr[i]);
//	}
//	putchar('\n');
//}
//
//void InsertList(Node *p, int i, Datatype x)               //����Ԫ��
//{
//	if(i<1||i>p->length+1)
//	{
//		printf("����λ�ò�����!\n");
//		return;
//	}
//	if (p->length == SIZE)
//	{
//		printf("˳�������!\n");
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
//void DestroyList(Node *p)                                 //����˳���
//{
//	free(p->arr);
//}
//
//void MergeList(Node *p1, Node *p2)               //����˳���ϲ�(�󲢼�)
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
//void Merge_List(Node *p1, Node *p2, Node *p3)     //�����ĺϲ�
//{
//	int *pa = p1->arr;                                      //ָ���һ��˳���ĵ�һ��Ԫ��
//	int *pb = p2->arr;                                    //ָ��ڶ���˳���ĵ�һ��Ԫ��
//	int *pa_last = (p1->arr) + p1->length - 1;         //ָ���һ��˳���ı�βԪ��
//	int *pb_last = (p2->arr) + p2->length - 1;            //ָ��ڶ���˳���ı�βԪ��
//	p3->length = p1->length + p2->length;                         
//	p3->arr = (Datatype*)malloc(p3->length*sizeof(Datatype));    //��ʼ������˳���
//	int *pc = p3->arr;                                             //ָ������˳���ĵ�һ��Ԫ��
//	while (pa <= pa_last&&pb <= pb_last)            //��һ��˳���û�ж��겢�ҵڶ���˳���û�ж���
//	{
//		if ((*pa) <= (*pb))                                    //�����һ��˳����Ԫ��С�ڵڶ���˳����Ԫ��
//		{
//			*pc = *pa;                                         //��Ԫ�ط�������˳���
//			pc++;                                                 //����˳���Ԫ�غ���
//			pa++;                                          //��һ��˳����Ԫ��ָ�����
//		}
//		else                                        //�����һ��˳����Ԫ�ش��ڵڶ���˳����Ԫ��
//		{
//			*pc = *pb;							//��Ԫ�ط�������˳���
//			pc++;                                        //����˳���Ԫ��ָ�����
//			pb++;                                       //�ڶ���˳����Ԫ��ָ�����
//		}
//	}
//	while (pa <= pa_last)                        //����ڶ���˳����ж����һ��˳���û�ж���
//	{
//		*pc = *pa;
//		pc++;
//		pa++;
//	}
//	while (pb <= pb_last)							 //�����һ��˳����ж���ڶ���˳���û�ж���
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

void InitList(pNode *p);                               //��ʼ������
void PrintfList(pNode *p);                               //��ӡ����
void DestoryList(pNode *p);                             //��������
void CreateList(pNode *p,Datatype x);                                   //ͷ��
void TailList(pNode *p, Datatype x);                                   //β��
void MergeList(pNode *p1, pNode *p2);                             //�ϲ������󲢼�
void Merge_List(pNode *p1, pNode *p2);                         //�ϲ�������������

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

void InitList(pNode *p)                               //��ʼ������
{
	*p = (pNode)malloc(sizeof(Node));
	(*p)->next = NULL;
}

void PrintfList(pNode *p)                               //��ӡ����
{
	pNode pL = (*p)->next;
	while (pL != NULL)
	{
		printf("%d ", pL->data);
		pL = pL->next;
	}
	putchar('\n');
}

void DestoryList(pNode *p)                             //��������
{
	pNode pL;
	while ((*p) != NULL)
	{
		pL = *p;
		*p = (*p)->next;
		free(pL);
	}
}

void CreateList(pNode *p, Datatype x)                                   //ͷ��
{
	pNode pnode;
	pnode = (pNode)malloc(sizeof(Node));
	pnode->data = x;
	pnode->next = (*p)->next;
	(*p)->next = pnode;
}
void TailList(pNode *p, Datatype x)                                   //β��
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

void MergeList(pNode *p1, pNode *p2)                             //�ϲ������󲢼�
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

void Merge_List(pNode *p1, pNode *p2)                         //�ϲ�������������
{
	pNode pa = (*p1)->next;                                       //ָ���һ���������Ԫ���
	pNode pb = (*p2)->next;							         //ָ��ڶ����������Ԫ���
	pNode pc = (*p1);                                             //ָ���һ�������ͷ���
	while (pa&&pb)                                                //pa��pb��Ϊ��������жϣ�����һ��Ϊ�����˳�ѭ��
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
	pc->next = pa ? pa : pb;                                 //����һ�������ж��꣬����һ�������ʣ�ಿ������pc->next;
	free(*p2);                                                      //�ͷŵڶ��������ͷ���
}
