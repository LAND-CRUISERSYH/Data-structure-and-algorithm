#include<stdio.h>
#include<string.h>

#define SIZE 20

typedef struct
{
	char ch[SIZE + 1];                 //�洢����һά����
	int length;							//���ĵ�ǰ����
}str;

int Index_BF(str S, str T);            //BF�㷨

//#define CHUNKSIZE 20
//
//typedef struct Chunk
//{
//	char ch[CHUNKSIZE];                 //���һ�����е��ַ�
//	struct Chunk *next;                    //ָ����һ����
//}Chunk;
//
//typedef struct
//{
//	Chunk *head, *tail;                    //����ͷָ���βָ��
//	int length;                                 //���ĵ�ǰ����
//}LStr;                                           //�ַ����Ŀ����ṹ

int main()
{
	str S, T;
	printf("�������һ���ַ���: ");
	gets(S.ch);
	getchar();
	printf("������ڶ����ַ���: ");
	gets(T.ch);
	getchar();
	S.length = strlen(S.ch) - 1;
	T.length = strlen(T.ch) - 1;
	printf("λ���±�Ϊ: %d\n", Index_BF(S, T));
	return 0;
}

int Index_BF(str S, str T)            //BF�㷨
{
	int i = 1, j = 1;                       //���±�1��ʼ�洢�ַ������±�0�ճ���
	while (i <= S.length&&j <= T.length)
	{
		if (S.ch[i] == T.ch[j])               //�������Ӵ�����ƥ����һ���ַ�
		{
			i++;
			j++;
		}
		else                                    //�������Ӵ�ָ��������¿�ʼ��һ��ƥ��
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length)
		return i - T.length;                     //����ƥ��ĵ�һ���ַ����±�
	else
		return 0;                                     //ģʽƥ�䲻�ɹ�
}
