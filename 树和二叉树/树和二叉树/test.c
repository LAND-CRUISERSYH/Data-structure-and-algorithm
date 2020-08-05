#include<stdio.h>

//#define MAXSIZE 100                                    //二叉树顺序定义
//
//typedef int Datatype;
//
//typedef Datatype SqBiTree[MAXSIZE];

//typedef int Datatype;                                   //二叉链表
//
//typedef struct BiNode {
//	Datatype data;
//	struct BiNode *lchild, *rchild;                //左右孩子指针
//}BiNode,*BiTree;

typedef int Datatype;

typedef struct TriTNode
{
	Datatype data;
	struct TriTNode *lchild, *parent, *rchild;                        //左孩子、双亲及右孩子指针
}TriTNode,*TriTree;

int main()
{
	return 0;
}