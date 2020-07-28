#include<stdio.h>
#include<stdlib.h>                   //�ṩmalloc()��free()����ԭ��

typedef int Datatype;

typedef struct Node                              //�����������ͺ�ָ�����ָ������
{
	Datatype data;									//����������
	struct Node *next;							//����ָ����
}Node,*pNode;									//pNodeΪָ�����ָ������


void InitList(pNode *p);                               //��ʼ������
int IsEmpty(pNode *p);                               //�ж������Ƿ�Ϊ��
void Destroy(pNode *p);								//��������
void Clear(pNode *p);                                  //�������
int GetLength(pNode *p);                            //���
void CreateList(pNode *p, Datatype x);            //ͷ��
void TailList(pNode *p, Datatype x);            //β��
void PrintList(pNode *p);                               //��ӡ����
pNode Tail_Pointer(pNode *p);                      //����βָ��
void MergeList(pNode *p1, pNode *p2);           //�ϲ�����ѭ������

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
	printf("LA��ĳ���Ϊ: %d\n", GetLength(&LA));
	TailList(&LB, 66);
	TailList(&LB, 77);
	TailList(&LB, 88);
	TailList(&LB, 99);
	PrintList(&LB);
	printf("LB��ĳ���Ϊ: %d\n", GetLength(&LB));
	LC = Tail_Pointer(&LA);
	LD = Tail_Pointer(&LB);
	MergeList(&LC, &LD);
	PrintList(&LA);
	printf("LA��ĳ���Ϊ: %d\n", GetLength(&LA));
	Destroy(&LA);
	return 0;
}

void InitList(pNode *p)                               //��ʼ������
{
	*p = (pNode)malloc(sizeof(Node));                   //��ͷָ��ָ��ͷ���
	(*p)->next = (*p);											//ͷ����ָ����ָ��ͷ���
}

int IsEmpty(pNode *p)                               //�ж������Ƿ�Ϊ��
{
	if ((*p)->next == (*p))                          //�ж�ͷ���ָ�����Ƿ�ָ��ͷ���
		return 1;										//Ϊ�շ���1
	return 0;											//��Ϊ�շ���0
}

void Destroy(pNode *p)							//��������
{
	pNode pL = (*p)->next;                       //��ָ��pLָ����Ԫ���
	(*p)->next = NULL;                             //��ͷ����ָ�����ÿ�
	*p = pL;                                              //ָ����Ԫ���
	while ((*p) != NULL)
	{
		pL = *p;
		*p = (*p)->next;               
		free(pL);                                          //�����ͷŽ��(����ͷ�ͷ���)
	}
}

void Clear(pNode *p)                                  //�������
{
	pNode pL = (*p)->next;                          //��ָ��ָ����Ԫ���
	pNode qL;
	while (pL != (*p))
	{
		qL = pL;
		pL = pL->next;
		free(qL);                                            //�����ͷŽ��
	}
	(*p)->next = (*p);                                //��ͷ����ָ����ָ���Լ�
}

int GetLength(pNode *p)                            //���
{
	int i = 0;
	pNode pL = (*p)->next;                          //��pLָ����Ԫ���
	while (pL!= (*p))                                      //��������ͳ��Ԫ�ظ���
	{
		i++;
		pL = pL->next;
	}
	return i;
}

void CreateList(pNode *p, Datatype x)            //ͷ��
{
	pNode pnode;
	pnode = (pNode)malloc(sizeof(Node));
	pnode->data = x;                                            //����һ��������Ϊx���½��
	pnode->next = (*p)->next;                              //�½���ָ����ָ��ͷ���ָ����ָ��Ľ��
	(*p)->next = pnode;                                    //ͷ���ָ����ָ���½��
}

void PrintList(pNode *p)                               //��ӡ����
{
	pNode pL = (*p)->next;
	while (pL != (*p))
	{
		printf("%d ", pL->data);
		pL = pL->next;
	}
	printf("\n");
}

void TailList(pNode *p, Datatype x)            //β��
{
	pNode pnode;
	pNode pL = (*p);
	pnode = (pNode)malloc(sizeof(Node)); 
	pnode->data = x;                                    //����һ��������Ϊx���½��
	while (pL->next!=(*p))
	{
		pL = pL->next;                                    //��λ����������һ�����
	}
	pL->next = pnode;                            //���һ������ָ����ָ���½��
	pnode->next = (*p);                            //�½���ָ����ָ��ͷ���
}

pNode Tail_Pointer(pNode *p)                      //����βָ��
{
	pNode pL = (*p);
	while (pL->next!= (*p))
	{
		pL = pL->next;
	}
	return pL;
}

void MergeList(pNode *p1, pNode *p2)           //�ϲ�����ѭ������
{
	pNode pL = (*p1)->next;                                             //�����һ�������ͷ���
	(*p1)->next = (*p2)->next->next;                      //����һ������ĩβ����ָ����ָ��ڶ����������Ԫ���
	free((*p2)->next);                                      //�ͷŵڶ��������ͷ���
	(*p2)->next = pL;                                     //���ڶ�������ĩβ����ָ����ָ���һ�������ͷ���
}