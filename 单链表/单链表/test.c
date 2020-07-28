#include<stdio.h>
#include<stdlib.h>               //�ṩmalloc()��free()����ԭ��

typedef int Datatype;

typedef struct Node              //����������ͺ�ָ�����ָ������
{
	Datatype data;					//����������
	struct  Node *next;			//����ָ����
}Node,*pNode;					//pNodeΪָ��ṹ��Node��ָ������

void InitList(pNode *p);             //������ĳ�ʼ��
int IsEmpty(pNode *p);              //�ж������Ƿ�Ϊ�� 
void DestroyList(pNode *p);        //���ٵ�����
void ClearList(pNode *p);           //�������
int GetLength(pNode *p);			//������ı�(����Ԫ�ظ���)
Datatype GetElem(pNode *p, int i);            //��ȡ���Ա��е�i��λ�õ�Ԫ��
int LocateList(pNode *p, Datatype x);        //����ָ������Ԫ�ػ�ȡ��Ԫ��λ��
void InsertList(pNode *p, int i, Datatype x);           //�ڵ�i�����ǰ�����½��
void DeleteList(pNode *p, int i);                       //ɾ����i�����
void CreateList(pNode *p, Datatype x);                 //ͷ�巨
void TailList(pNode *p, Datatype x);                     //β�巨
void PrintList(pNode *p);                                   //��ӡ����


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
	printf("55�������еĵ�%d��Ԫ��!\n", LocateList(&List, 55));
	printf("������Ԫ����: %d\n", GetElem(&List, 6));
	printf("����ı�Ϊ: %d\n", GetLength(&List));
	ClearList(&List);
	printf("����ı�Ϊ: %d\n", GetLength(&List));
	DestroyList(&List);
	return 0;
}

void InitList(pNode *p)             //������ĳ�ʼ��
{   
	*p = (pNode)malloc(sizeof(Node));             //��ͷָ��ָ��ͷ���
	(*p)->next = NULL;                    //ͷ����ָ�����ÿ�
}

int IsEmpty(pNode *p)              //�ж������Ƿ�Ϊ��
{
	if ((*p)->next == NULL)               //�ж�ͷ���ָ�����Ƿ�Ϊ��
		return 1;								//Ϊ�շ���1
	return 0;									//��Ϊ�շ���0
}

void DestroyList(pNode *p)        //���ٵ�����
{
	pNode pL;
	while ((*p) != NULL)
	{
		pL = *p;
		*p = (*p)->next;            
		free(pL);                            //�����ͷŽ��
	}
}

void ClearList(pNode *p)           //�������
{
	pNode pL = (*p)->next;
	pNode qL;
	while (pL)         
	{
		qL = pL->next;                              
		free(pL);												//�����ͷŽ��
		pL = qL;										
	}
	(*p)->next = NULL;                  //��ͷ���ָ��������Ϊ��
}

int GetLength(pNode *p)			//������ı�(����Ԫ�ظ���)
{
	int i = 0;
	pNode pL = (*p)->next;        //pLָ���һ�����
	while (pL != NULL)                 //����������ͳ�ƽ����
	{
		i++;
		pL = pL->next;
	}
	return i;
}

Datatype GetElem(pNode *p, int i)            //��ȡ���Ա��е�i��λ�õ�Ԫ��
{
	pNode pL = (*p)->next;
	int j = 1;
	if (i<1 || i>GetLength(p))                //�ж�����λ���Ƿ����
	{
		printf("�����λ�ò�����!\n");
		return 0;
	}
	if (IsEmpty(p))                                     //�ж������Ƿ�Ϊ��
	{
		printf("����Ϊ��!\n");
		return 0;
	}
	while (j < i)                 //���ɨ��ֱ��pָ���i��Ԫ��
	{
		pL = pL->next;
		j++;
	}
	return pL->data;
}

int LocateList(pNode *p, Datatype x)        //����ָ������Ԫ�ػ�ȡ��Ԫ��λ��
{
	pNode pL = (*p)->next;
	int j = 1;
	if (IsEmpty(p))                            //�ж������Ƿ�Ϊ��
	{
		printf("����Ϊ��!\n");
		return 0;
	}
	while ((pL->data!=x)&&(pL!=NULL))           
	{
		j++;
		pL = pL->next;
	}
	if (pL == NULL)                       //������������δ�ҵ���Ԫ���򷵻�0
	{
		printf("������û�и�Ԫ��!\n");
		return 0;
	}
	else
		return j;
}

void InsertList(pNode *p, int i, Datatype x)           //�ڵ�i�����ǰ�����½��
{
	pNode pnode;
	pNode pL = (*p);
	int j = 1;
	if (i < 1 || i > GetLength(p))                      //�ж�����λ���Ƿ����
	{
		printf("����λ�ò�����!\n");
		return;
	}
	pnode = (pNode)malloc(sizeof(Node));        
	pnode->data = x;                            //����һ��������Ϊx���½��pnode
	while (j < i)                                   //��λ����i-1�����
	{ 
		pL = pL->next; 
		j++;
	}
	pnode->next = pL->next;               //�½���ָ����ָ���i�����
	pL->next = pnode;                         //��i-1������ָ����ָ���½��
}

void DeleteList(pNode *p, int i)                       //ɾ����i�����
{
	pNode pL = (*p);
	pNode qL;
	int j = 1;
	if (IsEmpty(p))                              //�ж������Ƿ�Ϊ��
	{
		printf("����Ϊ��!\n");
		return;
	}
	if (i<1 || i>GetLength(p))            //�ж�����λ���Ƿ����
	{
		printf("����λ�ò��Ϸ�!\n");
		return;
	}
	while (j < i)                          //��λ����i-1�����
	{
		pL = pL->next;
		j++;
	}
	qL = pL->next;                       //�����i�����ĵ�ַ
	pL->next = pL->next->next;             //�õ�i-1������ָ����ָ���i+1�����
	free(qL);								//�ͷŵ�i�����Ŀռ�
}

void CreateList(pNode *p, Datatype x)                  //ͷ�巨
{
	pNode pnode;
	pnode = (pNode)malloc(sizeof(Node));      
	pnode->data = x;                                             //����ָ����Ϊx���½��
	pnode->next = (*p)->next;                             //���½���ָ����ָ��ͷ���ָ������ָ��Ľ��
	(*p)->next = pnode;                                          //��ͷ���ָ����ָ���½��
}

void TailList(pNode *p, Datatype x)                     //β�巨
{
	pNode pnode;
	pNode pL = (*p);
	pnode = (pNode)malloc(sizeof(Node));
	pnode->data = x;
	pnode->next = NULL;                                 //����ָ����ΪNULL��������Ϊx���½��
	while (pL->next != NULL)
	{
		pL = pL->next;	                                 //��ָ�붨λ����������һ��Ԫ��
	}
	pL->next = pnode;                                  //����������һ��Ԫ�ص�ָ����ָ���½��
}

void PrintList(pNode *p)                    //��ӡ����
{
	pNode pL = (*p);
	while (pL->next != NULL)
	{
		printf("%d ", pL->next->data);
		pL = pL->next;
	}
	putchar('\n');
}