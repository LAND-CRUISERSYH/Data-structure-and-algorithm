#include<stdio.h>

//#define MAXSIZE 100                                    //������˳����
//
//typedef int Datatype;
//
//typedef Datatype SqBiTree[MAXSIZE];

//typedef int Datatype;                                   //��������
//
//typedef struct BiNode {
//	Datatype data;
//	struct BiNode *lchild, *rchild;                //���Һ���ָ��
//}BiNode,*BiTree;

typedef int Datatype;

typedef struct TriTNode
{
	Datatype data;
	struct TriTNode *lchild, *parent, *rchild;                        //���ӡ�˫�׼��Һ���ָ��
}TriTNode,*TriTree;

int main()
{
	return 0;
}