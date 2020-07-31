#include<stdio.h>
#include<stdlib.h>

#define SIZE 10                              //�����г���

typedef int Datatype;
typedef struct
{
	Datatype *arr;                         //��ʼ���Ķ�̬����洢�ռ�
	int front;									//��ͷԪ�ص��±�
	int rear;									//ָ�����βԪ�ص���һ��λ��
}SqQueue;

void InitQueue(SqQueue *p);                      //���еĳ�ʼ��
int GetLength(SqQueue *p);                    //����г���
void EnQueue(SqQueue *p, Datatype x);            //���
Datatype OutQueue(SqQueue *p);                     //����
void DestoryQueue(SqQueue *p);                    //���ٶ���

int main()
{
	SqQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);
	EnQueue(&Q, 4);
	EnQueue(&Q, 5);
	printf("���г���Ϊ: %d\n", GetLength(&Q));
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", OutQueue(&Q));
	}
	putchar('\n');
	DestoryQueue(&Q);
}

void InitQueue(SqQueue *p)                      //���еĳ�ʼ��
{
	p->arr = (Datatype*)malloc(SIZE* sizeof(Datatype));                  //��������ռ�
	if (!p->arr)                                                    //�жϷ����Ƿ�ɹ�
	{
		printf("�ڴ����ʧ��!\n");
		return;
	}
	p->front =p->rear= 0;                          //��ͷ��β�±���0������Ϊ��
}

int GetLength(SqQueue *p)                    //����г���
{
	return ((p->rear - p->front + SIZE) % SIZE);               //һ��Ҫȡ��(��ȡ�����Ϊ��ʱ�������)
}

void EnQueue(SqQueue *p, Datatype x)            //���
{
	if ((p->rear + 1) % SIZE == p->front)               //�ж��Ƿ����
	{
		printf("����!\n");
		return;
	}
	p->arr[p->rear] = x;                                   //������Ԫ�ط���rear�±�λ��
	p->rear = (p->rear + 1) % SIZE;                    //�ı�rear�±�
}

Datatype OutQueue(SqQueue *p)                     //����
{
	Datatype temp;
	if (p->front == p->rear)                              //�ж��Ƿ�ӿ�
	{
		printf("�ӿ�!\n");
		return 0;
	}
	temp = p->arr[p->front];                         //��ȡ��ͷԪ��
	p->front = (p->front + 1) % SIZE;           //�޸Ķ�ͷ�±�
	return temp;                                           //���ض�ͷ����
} 

void DestoryQueue(SqQueue *p)                    //���ٶ���
{
	if (p->arr)
		free(p->arr);                    
}