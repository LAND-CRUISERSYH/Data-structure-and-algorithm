//#include<stdio.h>
//#include<stdlib.h>
//
//#define SIZE 10
//
//typedef int Datatype;
//typedef struct Stack
//{
//	Datatype *base;                         //ջ��ָ��
//	Datatype *top;							//ջ��ָ��
//	int stacksize;							//ջ���õ��������
//}SqStack;
//
//void InitStack(SqStack *p);                  //˳��ջ�ĳ�ʼ��
//int IsEmpty(SqStack *p);                     //�ж�ջ�Ƿ�Ϊ��
//int GetLength(SqStack *p);                 //��˳��ջ����
//void ClearStack(SqStack *p);             //���˳��ջ
//void DestroyStack(SqStack *p);        //����˳��ջ
//void PushStack(SqStack *p, Datatype x);          //��ջ
//Datatype PopStack(SqStack *p);                      //��ջ
//void PrintStack(SqStack *p);                       //��ӡ
//
//int main()
//{
//	SqStack S;
//	InitStack(&S);
//	PushStack(&S, 1);
//	PushStack(&S, 2);
//	PushStack(&S, 3);
//	PushStack(&S, 4);
//	PushStack(&S, 5);
//	printf("ջ��Ϊ: %d\n", GetLength(&S));
//	PrintStack(&S);
//	while (!IsEmpty(&S))
//	{
//		printf("%d ", PopStack(&S));
//	}
//	putchar('\n');
//	DestroyStack(&S);
//	return 0;
//}
//
//void InitStack(SqStack *p)                  //˳��ջ�ĳ�ʼ��
//{
//	p->base = (Datatype*)malloc(SIZE * sizeof(Datatype));
//	if (!p->base)                                          
//	{
//		printf("�ڴ����ʧ��!\n");                //�洢����ʧ��
//		return;
//	}
//	p->top = p->base;                         //ջ��ָ�����ջ��ָ��
//	p->stacksize = SIZE;
//}
//
//int IsEmpty(SqStack *p)                     //�ж�ջ�Ƿ�Ϊ��
//{
//	if (p->base == p->top)           //��ջΪ�շ���1
//		return 1;
//	return 0;									//��Ϊ�շ���0
//}
//
//int GetLength(SqStack *p)                 //��˳��ջ����
//{
//	return p->top - p->base;             //ջ��ָ���ջ��ָ��Ĳ�ֵ
//}
//
//void ClearStack(SqStack *p)             //���˳��ջ
//{
//	if (p->base)                                   //���ջ���ڣ���ջ��ָ��ָ��ջ��
//		p->top = p->base; 	
//}
//
//void DestroyStack(SqStack *p)        //����˳��ջ
//{
//	if (p->base)                                     //�ж�ջ�Ƿ����
//	{ 
//		free(p->base);                          //����˳��ջ
//		p->stacksize = 0;
//		p->base = p->top = NULL;
//	}
//}
//
//void PushStack(SqStack *p, Datatype x)          //��ջ
//{
//	if (p->top - p->base == p->stacksize)         //�ж��Ƿ�ջ��
//	{
//		printf("ջ��!\n");
//		return;
//	}
//	*(p->top) = x;                          //Ԫ����ջ
//	p->top++;                             //ջ��ָ��+1
//}  
//
//Datatype PopStack(SqStack *p)                      //��ջ
//{
//	if (IsEmpty(p))                      //�ж��Ƿ�ջ��
//	{
//		printf("ջ��!\n");
//		return 0;
//	}
//	p->top--;                            //ջ��Ԫ��-1
//	return *(p->top);                      //����ջ��Ԫ��
//}
//
//void PrintStack(SqStack *p)                       //��ӡ
//{
//	for (int i = 0; i < p->top - p->base; i++)
//	{
//		printf("%d ", p->base[i]);
//	}
//	putchar('\n');
//}
#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;
typedef struct Node
{
	Datatype data;
	struct Node *next;
}Node,*pNode;

void InitStack(pNode *p);                    //��ջ�ĳ�ʼ��
int IsEmpty(pNode *p);                       //�ж���ջ�Ƿ�Ϊ��
void PushStack(pNode *p, Datatype x);          //��ջ
Datatype PopStack(pNode *p);                 //��ջ
void Destroy(pNode *p);                         //������ջ
int GetLength(pNode *p);                         //����ջ����

int main()
{
	pNode S;
	InitStack(&S);
	PushStack(&S, 6);
	PushStack(&S, 7);
	PushStack(&S, 8);
	PushStack(&S, 9);
	PushStack(&S, 10);
	int num = GetLength(&S);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", PopStack(&S));
	}
	putchar('\n');
	Destroy(&S);
	return 0;
}

void InitStack(pNode *p)                    //��ջ�ĳ�ʼ��
{
	*p = NULL;                                      //ͷָ��ָ���
}

int IsEmpty(pNode *p)                       //�ж���ջ�Ƿ�Ϊ��
{
	if (*p == NULL)                               //Ϊ�շ���1
		return 1; 
	return 0;                                        //��Ϊ�շ���0
}

void PushStack(pNode *p, Datatype x)          //��ջ
{
	pNode pnode = (pNode)malloc(sizeof(Node));          
	pnode->data = x;                              //����������Ϊx���½��
	pnode->next = (*p);                      //���½�����ջ��
	(*p) = pnode;                               //�޸�ջ��ָ��
}

Datatype PopStack(pNode *p)                 //��ջ
{
	pNode pL;                              
	Datatype temp;                        //�ݴ��ջ��Ԫ������
	if (IsEmpty(p))                           //�ж�ջ�Ƿ�Ϊ��
	{
		printf("ջ��!\n");
		return 0;
	}
	pL = *p;
	(*p) = (*p)->next;                   //��ջ��ָ�����
	temp = pL->data;                  
	free(pL);                                  //�ͷų�ջ��Ԫ���ڴ�
	return temp;                             //���ؽ������
}

void Destroy(pNode *p)                         //������ջ
{
	pNode pL;
	while ((*p) != NULL)
	{
		pL = *p;
		(*p) = (*p)->next;        
		free(pL);                                     //�����ͷŽ��
	}
}

int GetLength(pNode *p)                         //����ջ����
{
	int i = 0;
	pNode pL = *p;
	while (pL != NULL)                     
	{
		i++;
		pL = pL->next;
	}
	return i;
}
