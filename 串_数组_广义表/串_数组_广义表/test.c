#include<stdio.h>
#include<string.h>

//#define SIZE 20
//
//typedef struct
//{
//	char ch[SIZE + 1];                 //�洢����һά����
//	int length;							//���ĵ�ǰ����
//}str;

#define CHUNKSIZE 20

typedef struct Chunk
{
	char ch[CHUNKSIZE];                 //���һ�����е��ַ�
	struct Chunk *next;                    //ָ����һ����
}Chunk;

typedef struct
{
	Chunk *head, *tail;                    //����ͷָ���βָ��
	int length;                                 //���ĵ�ǰ����
}LStr;                                           //�ַ����Ŀ����ṹ

int main()
{
	
	return 0;
}
