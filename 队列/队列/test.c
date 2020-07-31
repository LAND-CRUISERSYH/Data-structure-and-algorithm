//#include<stdio.h>
//#include<stdlib.h>
//
//#define SIZE 10                              //�����г���
//
//typedef int Datatype;
//typedef struct
//{
//	Datatype *arr;                         //��ʼ���Ķ�̬����洢�ռ�
//	int front;									//��ͷԪ�ص��±�
//	int rear;									//ָ�����βԪ�ص���һ��λ��
//}SqQueue;
//
//void InitQueue(SqQueue *p);                      //���еĳ�ʼ��
//int GetLength(SqQueue *p);                    //����г���
//void EnQueue(SqQueue *p, Datatype x);            //���
//Datatype OutQueue(SqQueue *p);                     //����
//void DestoryQueue(SqQueue *p);                    //���ٶ���
//
//int main()
//{
//	SqQueue Q;
//	InitQueue(&Q);
//	EnQueue(&Q, 1);
//	EnQueue(&Q, 2);
//	EnQueue(&Q, 3);
//	EnQueue(&Q, 4);
//	EnQueue(&Q, 5);
//	printf("���г���Ϊ: %d\n", GetLength(&Q));
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", OutQueue(&Q));
//	}
//	putchar('\n');
//	DestoryQueue(&Q);
//}
//
//void InitQueue(SqQueue *p)                      //���еĳ�ʼ��
//{
//	p->arr = (Datatype*)malloc(SIZE* sizeof(Datatype));                  //��������ռ�
//	if (!p->arr)                                                    //�жϷ����Ƿ�ɹ�
//	{
//		printf("�ڴ����ʧ��!\n");
//		return;
//	}
//	p->front =p->rear= 0;                          //��ͷ��β�±���0������Ϊ��
//}
//
//int GetLength(SqQueue *p)                    //����г���
//{
//	return ((p->rear - p->front + SIZE) % SIZE);               //һ��Ҫȡ��(��ȡ�����Ϊ��ʱ�������)
//}
//
//void EnQueue(SqQueue *p, Datatype x)            //���
//{
//	if ((p->rear + 1) % SIZE == p->front)               //�ж��Ƿ����
//	{
//		printf("����!\n");
//		return;
//	}
//	p->arr[p->rear] = x;                                   //������Ԫ�ط���rear�±�λ��
//	p->rear = (p->rear + 1) % SIZE;                    //�ı�rear�±�
//}
//
//Datatype OutQueue(SqQueue *p)                     //����
//{
//	Datatype temp;
//	if (p->front == p->rear)                              //�ж��Ƿ�ӿ�
//	{
//		printf("�ӿ�!\n");
//		return 0;
//	}
//	temp = p->arr[p->front];                         //��ȡ��ͷԪ��
//	p->front = (p->front + 1) % SIZE;           //�޸Ķ�ͷ�±�
//	return temp;                                           //���ض�ͷ����
//} 
//
//void DestoryQueue(SqQueue *p)                    //���ٶ���
//{
//	if (p->arr)
//		free(p->arr);                    
//}
#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;
typedef struct Qnode
{
	Datatype data;                             //���������
	struct Qnode *next;                         //���ָ����
}Qnode,*pQnode;

typedef struct LinkQueue
{
	pQnode front;                             //��ͷָ��
	pQnode rear;                             //��βָ��
}LinkQueue;

void InitQueue(LinkQueue *p);              //��ʼ��������
void Destroy(LinkQueue *p);                  //����������
void EnQueue(LinkQueue *p, Datatype x);    //���
void OutQueue(LinkQueue *p);                      //����
Datatype GetHead(LinkQueue *p);                   //ȡ��ͷԪ��
int GetLength(LinkQueue *p);                       //����г���

int main()
{
	LinkQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, 2);
	EnQueue(&Q, 6);
	EnQueue(&Q, 7);
	EnQueue(&Q, 8);
	EnQueue(&Q, 9);
	printf("���г���Ϊ: %d\n", GetLength(&Q));
	printf("��ͷԪ��Ϊ: %d\n", GetHead(&Q));
	OutQueue(&Q);
	OutQueue(&Q);
	printf("���г���Ϊ: %d\n", GetLength(&Q));
	printf("��ͷԪ��Ϊ: %d\n", GetHead(&Q));
	Destroy(&Q);
	return 0;
}

void InitQueue(LinkQueue *p)              //��ʼ��������
{
	p->front = p->rear = (pQnode)malloc(sizeof(Qnode));   //����洢�ռ�
	if (!p->front)                                      //�ڴ��Ƿ����ɹ�
	{
		printf("�ڴ����ʧ��!\n");
		return;
	}
	p->front->next = NULL;               //ͷ���ָ�����ÿ�
}

void Destroy(LinkQueue *p)                  //����������
{
	pQnode pL;
	while (p->front)
	{
		pL = p->front->next;
		free(p->front);                       //�����ͷ����н��
		p->front = pL;
	}
}

void EnQueue(LinkQueue *p, Datatype x)    //���
{
	pQnode temp;
	temp = (pQnode)malloc(sizeof(Qnode));
	if (!temp)                              //�ڴ��Ƿ����ɹ�
	{
		printf("�ڴ����ʧ��!\n");
		return;
	}
	temp->data = x;                      //����������Ϊx��ָ����ΪNULL���½��
	temp->next = NULL;
	p->rear->next = temp;               //���½�������ڶ�β
	p->rear = temp;                          //��βָ��ָ���β
}

void OutQueue(LinkQueue *p)                      //����
{
	pQnode temp;
	if (p->front == p->rear)
	{
		printf("�ӿ�!\n");
		return;                            
	} 
	temp = p->front->next;                              //ָ���ͷԪ��
	p->front->next = temp->next;            //����ͷԪ�ص�next���ӵ�ͷ���
	if (p->rear == temp)
		p->rear = p->front;                           //������н���һ��Ԫ��
	free(temp);                                       //�ͷŶ�ͷԪ��
}

Datatype GetHead(LinkQueue *p)                   //ȡ��ͷԪ��
{
	if (p->front == p->rear)                               //�����Ƿ�ӿ�
	{
		printf("�ӿ�!\n");
		return 0;
	}
	return p->front->next->data;                      //���ض�ͷԪ��
}

int GetLength(LinkQueue *p)                       //����г���
{
	pQnode pL = p->front->next;
	int i = 0;
	while (pL != NULL)
	{
		i++;
		pL = pL->next;
	}
	return i;
}