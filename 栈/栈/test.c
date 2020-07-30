#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef int Datatype;
typedef struct Stack
{
	Datatype *base;                         //ջ��ָ��
	Datatype *top;							//ջ��ָ��
	int stacksize;							//ջ���õ��������
}SqStack;

void InitStack(SqStack *p);                  //˳��ջ�ĳ�ʼ��
int IsEmpty(SqStack *p);                     //�ж�ջ�Ƿ�Ϊ��
int GetLength(SqStack *p);                 //��˳��ջ����
void ClearStack(SqStack *p);             //���˳��ջ
void DestroyStack(SqStack *p);        //����˳��ջ
void PushStack(SqStack *p, Datatype x);          //��ջ

int main()
{
	return 0;
}

void InitStack(SqStack *p)                  //˳��ջ�ĳ�ʼ��
{
	p->base = (Datatype*)malloc(SIZE * sizeof(Datatype));
	if (!p->base)                                          
	{
		printf("�ڴ����ʧ��!\n");                //�洢����ʧ��
		return;
	}
	p->top = p->base;                         //ջ��ָ�����ջ��ָ��
	p->stacksize = SIZE;
}

int IsEmpty(SqStack *p)                     //�ж�ջ�Ƿ�Ϊ��
{
	if (p->base == p->top)           //��ջΪ�շ���1
		return 1;
	return 0;									//��Ϊ�շ���0
}

int GetLength(SqStack *p)                 //��˳��ջ����
{
	return p->top - p->base;             //ջ��ָ���ջ��ָ��Ĳ�ֵ
}

void ClearStack(SqStack *p)             //���˳��ջ
{
	if (p->base)                                   //���ջ���ڣ���ջ��ָ��ָ��ջ��
		p->top = p->base; 	
}

void DestroyStack(SqStack *p)        //����˳��ջ
{
	if (p->base)                                     //�ж�ջ�Ƿ����
	{ 
		free(p->base);                          //����˳��ջ
		p->stacksize = 0;
		p->base = p->top = NULL;
	}
}

void PushStack(SqStack *p, Datatype x)          //��ջ
{
	if (p->top - p->base == p->stacksize)         //�ж��Ƿ�ջ��
	{
		printf("ջ��!\n");
		return;
	}
	*(p->top) = x;                          //Ԫ����ջ
	p->top++;                             //ջ��ָ��+1
}       