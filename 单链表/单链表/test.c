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


int main()
{
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