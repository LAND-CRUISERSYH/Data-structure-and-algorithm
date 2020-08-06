#include<stdio.h>
#include<stdlib.h>


typedef char Datatype;
typedef struct BiNode
{
	Datatype data;                                        //数据域
	struct BiNode *lchild, *rchild;					//左右孩子指针
}BiNode, *BiTree;

void PreOrderTraverse(BiTree T);            //先序遍历
void InOrderTraverse(BiTree T);              //中序遍历
void PostOrderTraverse(BiTree T);         //后序遍历
void CreateBiTree(BiTree *T);                 //二叉树的建立


int main()
{

}

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
		*T = NULL;
	else
	{
		if (!(*T = (BiNode *)malloc(sizeof(BiNode))))
			return;
		(*T)->data = ch;            //生成根结点
		CreateBiTree((*T)->lchild);   //构造左子树
		CreateBiTree((*T)->rchild);  //构造右子树
	}
}