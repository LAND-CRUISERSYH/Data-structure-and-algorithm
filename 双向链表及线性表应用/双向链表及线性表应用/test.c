#include<stdio.h>
#include<stdlib.h>

//typedef int Datatype;
//
//typedef struct Node
//{
//	Datatype data;
//	struct Node *front, *next;                                        //ǰ��ָ����ͺ��ָ����
//}Node,*pNode; 

//void InsertList(pNode *p, int i, Datatype x);                    //˫������Ĳ���
//void DeleteList(pNode *p, int i);                                   //˫�������ɾ��

//int main()
//{
//	return 0;
//}

//void InsertList(pNode *p, int i, Datatype x)                    //˫������Ĳ���
//{
//	int length = 0;                                                           //�����
//	pNode pL = (*p);
//	pNode qL = (*p);                                                         //��λ����i�����
//	int j = 0;
//	pNode pnode;
//	pnode = (pNode)malloc(sizeof(Node));
//	pnode->data = x;                                                   //����������Ϊx���½��
//	if ((*p)->next == NULL)                                               //�ж������Ƿ�Ϊ��
//	{
//		printf("����Ϊ��!\n");
//		return;
//	}
//	while (pL->next != NULL)
//	{
//		length++;                                                             //���ε�������
//		pL = pL->next;             
//	}
//	if (i<1 || i>length)                                                  //�ж�����λ���Ƿ����
//	{
//		printf("����λ�ò�����!\n");
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

//void DeleteList(pNode *p, int i)                                   //˫�������ɾ��
//{
//	int length = 0;                                                           //�����
//	pNode pL = (*p);
//	pNode qL = (*p);                                                         //��λ����i�����
//	int j = 0;
//	if ((*p)->next == NULL)                                               //�ж������Ƿ�Ϊ��
//	{
//		printf("����Ϊ��!\n");
//		return;
//	}
//	while (pL->next != NULL)
//	{
//		length++;                                                             //���ε�������
//		pL = pL->next;
//	}
//	if (i<1 || i>length)                                                  //�ж�����λ���Ƿ����
//	{
//		printf("����λ�ò�����!\n");
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