#include<stdio.h>
#include<stdlib.h>


typedef char Datatype;
typedef struct BiNode
{
	Datatype data;                                        //数据域
	struct BiNode *lchild, *rchild;					//左右孩子指针
}BiNode, *BiTree;

typedef struct BiThrNode
{
	Datatype data;
	int ltag, rtag;
	struct BiThrNode *lchild, *rchild;
}BiThrNode,*BiThrTree;

void PreOrderTraverse(BiTree T);            //先序遍历
void InOrderTraverse(BiTree T);              //中序遍历
void PostOrderTraverse(BiTree T);         //后序遍历
void CreateBiTree(BiTree *T);                 //二叉树的建立
void Copy(BiTree T, BiTree *NewT);         //二叉树的复制
int Depth(BiTree T);                                //求二叉树深度
int NodeCount(BiTree T);                       //求二叉树结点总数
int LeadCount(BiTree T);                        //求二叉树叶子结点数


void PreOrderTraverse(BiTree T)            //先序遍历
{
	if (T == NULL)
		return;
	printf("%c ", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)              //中序遍历
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c ", T->data);
	InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)         //后序遍历
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c ", T->data);
}

void CreateBiTree(BiTree *T)                 //二叉树的建立
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		(*T) = NULL;
	else
	{
		if (!((*T) = (BiNode *)malloc(sizeof(BiNode))))
			return;
		(*T)->data = ch;            //生成根结点
		CreateBiTree(&(*T)->lchild);   //构造左子树
		CreateBiTree(&(*T)->rchild);  //构造右子树
	}
}

void Copy(BiTree T, BiTree *NewT)         //二叉树的复制
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
			printf("分配失败!\n");
			return;
		}
		(*NewT)->data = T->data;
		Copy(T->lchild, &(*NewT)->lchild);
		Copy(T->rchild, &(*NewT)->rchild);
	}
}

int Depth(BiTree T)                                //求二叉树深度
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

int NodeCount(BiTree T)                       //求二叉树结点总数
{
	if (T == NULL)
		return 0;
	else
	{
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}

int LeadCount(BiTree T)                        //求二叉树叶子结点数
{
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
		return LeadCount(T->lchild) + LeadCount(T->rchild);
}