#include<stdio.h>
#include<stdlib.h>                //malloc()��free()����ԭ��

#define LIST_SIZE 20           //˳����пɴ��Ԫ�ظ���

typedef int Datatype;

typedef struct {
	Datatype *pL;
	int length;                    //˳���Ԫ�ظ���(��)
}SqList;

void InitList(SqList *p);              //��ʼ��˳���


int main()
{
	//SqList L;                   //����һ��˳���
	printf("hello world");
	return 0; 
}

void InitList(SqList *p)
{
	p->pL = (Datatype*)malloc(LIST_SIZE * sizeof(Datatype));    //��̬�����ڴ�
	if (p->pL == NULL)
		exit(1);                               //�ڴ����ʧ��
	p->length = 0;                  //��Ϊ0��
}
