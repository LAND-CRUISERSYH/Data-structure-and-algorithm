#include<stdio.h>
#include<stdlib.h>

#define SIZE 10                              //�����г���

typedef int Datatype;
typedef struct
{
	Datatype *arr;                         //��ʼ���Ķ�̬����洢�ռ�
	int front;									//��ͷԪ�ص��±�
	int rear;									//��βԪ�ص��±�
}SqQueue;