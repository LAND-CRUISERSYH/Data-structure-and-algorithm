#include<stdio.h>
#include<stdlib.h>                //malloc()��free()����ԭ��

#define LIST_SIZE 20           //˳����пɴ��Ԫ�ظ���

typedef int Datatype;

typedef struct {
	Datatype *pL;
	int length;                    //˳���Ԫ�ظ���(��)
}SqList;

void InitList(SqList *p);              //��ʼ��˳���
void DestroyList(SqList * p);           //����˳���
void ClearList(SqList * p);           //���˳���
int GetLength(SqList * p);           //��˳�����
int IsEmpty(SqList *p);              //�ж�˳����Ƿ�Ϊ��
Datatype GetElem(SqList *p, int i);        //��ȡ��i��λ�õ�����Ԫ��
int LocateElem(SqList *p, Datatype x);     //����˳�����ĳһ����Ԫ�ص�λ��
void InsertList(SqList *p, int i, Datatype x);       //˳����в���ĳ��Ԫ�� 
void DeleteList(SqList *p, int i);       //˳�����ɾ��ĳ��Ԫ�� 
void PrintList(SqList *p);                 //��ӡ˳���



int main()
{

	SqList L;                   //����һ��˳���
	InitList(&L);
	InsertList(&L, 1, 1);
	InsertList(&L, 2, 2);
	InsertList(&L, 3, 3);
	InsertList(&L, 4, 5);
	PrintList(&L);
	printf("˳���Ԫ�ظ���: %d\n", GetLength(&L));
	InsertList(&L, 4, 4);
	PrintList(&L);
	printf("˳���Ԫ�ظ���: %d\n", GetLength(&L));
	printf("4��˳����е�λ��: %d\n", LocateElem(&L, 4));
	printf("��2��Ԫ��Ϊ: %d\n", GetElem(&L, 2));
	ClearList(&L);
	printf("˳���Ԫ�ظ���: %d\n", GetLength(&L));
	DestroyList(&L);
	return 0; 
}

void InitList(SqList *p)
{
	p->pL = (Datatype*)malloc(LIST_SIZE * sizeof(Datatype));    //��̬�����ڴ�
	if (p->pL == NULL)
	{
		printf("�ڴ����ʧ��!\n");
		return;                               //�ڴ����ʧ��
	}
	p->length = 0;                  //��Ϊ0��
}

void DestroyList(SqList * p)           //����˳���
{
	if (p->pL)
		free(p->pL);					//�ͷŴ洢�ռ�
}

void ClearList(SqList * p)           //���˳���
{
	p->length = 0;                   //��˳���ĳ�����Ϊ0
}

int GetLength(SqList * p)           //��˳�����
{
	return p->length;
}

int IsEmpty(SqList *p)              //�ж�˳����Ƿ�Ϊ��
{
	if (p->length == 0)
		return 1;               //Ϊ�շ���1
	else
		return 0;              //��Ϊ�շ���0
}

Datatype GetElem(SqList *p, int i)        //��ȡ��i��λ�õ�����Ԫ��
{
	if (IsEmpty(p))           //�ж�˳����Ƿ�Ϊ��
	{
		printf("˳���Ϊ��!\n");
		return  0;
	}
	else if (i<1 || i>p->length)       //�ж�����λ���Ƿ����
	{
		printf("�����λ�ò�����!\n");
		return 0;
	}
	else											//������Ӧλ�õ�����Ԫ��
		return p->pL[i - 1];
}

int LocateElem(SqList *p, Datatype x)     //����˳�����ĳһ����Ԫ�ص�λ��
{
	if (IsEmpty(p))                                 //�ж�˳����Ƿ�Ϊ��
	{
		printf("˳���Ϊ��!\n");
		return -1;
	}
	for (int i = 0; i < p->length; i++)         
	{
		if (x == p->pL[i])
			return i + 1;                         //���ҳɹ�������Ԫ����˳����е�λ��
	} 
	return 0;                                       //����ʧ�ܣ�����0
}

void InsertList(SqList *p, int i, Datatype x)       //˳����в���ĳ��Ԫ��
{
	if (i<1 || i>p->length + 1)                       //�жϲ���λ���Ƿ�Ϸ�
	{
		printf("�����λ�ò��Ϸ�!\n");      
		return;
	}
	if (p->length == LIST_SIZE)                   //�ж�˳����Ƿ�����
	{
		printf("˳�������!\n");
		return;
	}
	else
	{
		for (int j = p->length - 1; j >= i-1; j--)        
		{
			p->pL[j + 1] = p->pL[j];					  //��Ԫ����������ƶ�
		}
		p->pL[i - 1] = x;                                   //��x���뵽�±�Ϊi-1��λ��(��˳���ĵ�i��λ��)
		p->length++;                                      //˳����Ԫ�ظ���+ 1
	}
}

void DeleteList(SqList *p, int i)       //˳�����ɾ��ĳ��Ԫ�� 
{
	if (IsEmpty(p))                            //�ж�˳����Ƿ�Ϊ��
	{
		printf("˳���Ϊ��!\n");
		return;
	}
	if (i<1 || i>p->length)                //�ж�ɾ��λ���Ƿ�Ϸ�
	{
		printf("ɾ����λ�ò��Ϸ�!\n");
		return;
	}
	else
	{
		for (int j = i ; j <= p->length-1; j++)          
			p->pL[j-1] = p->pL[j];				//��Ԫ��������ǰ�ƶ�
		p->length--;									//˳����Ԫ�ظ���-1
	}
}

void PrintList(SqList *p)                 //��ӡ˳���
{
	for (int i = 0; i < p->length; i++)
		printf("%d ", p->pL[i]);
	printf("\n");
}
