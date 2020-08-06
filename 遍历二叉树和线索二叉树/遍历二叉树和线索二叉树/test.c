#include<stdio.h>
#include<stdlib.h>


typedef char Datatype;
typedef struct BiNode
{
	Datatype data;                                        //������
	struct BiNode *lchild, *rchild;					//���Һ���ָ��
}BiNode, *BiTree;

void PreOrderTraverse(BiTree T);            //�������
void InOrderTraverse(BiTree T);              //�������
void PostOrderTraverse(BiTree T);         //�������
void CreateBiTree(BiTree *T);                 //�������Ľ���


int main()
{

}

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
		*T = NULL;
	else
	{
		if (!(*T = (BiNode *)malloc(sizeof(BiNode))))
			return;
		(*T)->data = ch;            //���ɸ����
		CreateBiTree((*T)->lchild);   //����������
		CreateBiTree((*T)->rchild);  //����������
	}
}