#include<stdio.h>
#include<stdlib.h>


typedef char Datatype;
typedef struct BiNode
{
	Datatype data;                                        //������
	struct BiNode *lchild, *rchild;					//���Һ���ָ��
}BiNode, *BiTree;

typedef struct BiThrNode
{
	Datatype data;
	int ltag, rtag;
	struct BiThrNode *lchild, *rchild;
}BiThrNode,*BiThrTree;

void PreOrderTraverse(BiTree T);            //�������
void InOrderTraverse(BiTree T);              //�������
void PostOrderTraverse(BiTree T);         //�������
void CreateBiTree(BiTree *T);                 //�������Ľ���
void Copy(BiTree T, BiTree *NewT);         //�������ĸ���
int Depth(BiTree T);                                //����������
int NodeCount(BiTree T);                       //��������������
int LeadCount(BiTree T);                        //�������Ҷ�ӽ����


void PreOrderTraverse(BiTree T)            //�������
{
	if (T == NULL)
		return;
	printf("%c ", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)              //�������
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c ", T->data);
	InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)         //�������
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c ", T->data);
}

void CreateBiTree(BiTree *T)                 //�������Ľ���
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		(*T) = NULL;
	else
	{
		if (!((*T) = (BiNode *)malloc(sizeof(BiNode))))
			return;
		(*T)->data = ch;            //���ɸ����
		CreateBiTree(&(*T)->lchild);   //����������
		CreateBiTree(&(*T)->rchild);  //����������
	}
}

void Copy(BiTree T, BiTree *NewT)         //�������ĸ���
{
	if (T == NULL)
	{
		(*NewT) == NULL;
		return;
	}
	else
	{
		(*NewT) = (BiTree)malloc(sizeof(BiNode));
		if (!(*NewT))
		{
			printf("����ʧ��!\n");
			return;
		}
		(*NewT)->data = T->data;
		Copy(T->lchild, &(*NewT)->lchild);
		Copy(T->rchild, &(*NewT)->rchild);
	}
}

int Depth(BiTree T)                                //����������
{
	if (T == NULL)
		return 0;
	else
	{
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		return (m > n) ? (m + 1) : (n + 1);
	}
}

int NodeCount(BiTree T)                       //��������������
{
	if (T == NULL)
		return 0;
	else
	{
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}

int LeadCount(BiTree T)                        //�������Ҷ�ӽ����
{
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
		return LeadCount(T->lchild) + LeadCount(T->rchild);
}