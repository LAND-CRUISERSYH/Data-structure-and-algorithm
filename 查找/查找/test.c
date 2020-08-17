//#include<stdio.h>
//
//typedef int Keytype;
//typedef struct
//{
//	Keytype key;
//}ElemType;
//
//typedef struct
//{
//	ElemType *R;
//	int length;
//}SSTable;
//
////int Search_Seq(SSTable ST, Keytype key)     //顺序查找
////{
////	for (int i = ST.length; i >= 1; i--)
////	{
////		if (ST.R[i].key == key)
////			return i;
////	}
////	return 0;
////}
//
////int Search_Seq(SSTable ST, Keytype key)            //顺序查找----另一种形式
////{
////	int i = ST.length;
////	for (i = ST.length; ST.R[i].key != key; i--)
////	{
////		if (i <= 0)
////			break;
////	}
////	if (i > 0)
////		return i;
////	else
////		return 0;
////}
//
////int Search_Seq(SSTable ST, Keytype key)                  //顺序查找---加哨兵的形式
////{
////	ST.R[0].key = key;
////	int i = ST.length;
////	for (i = ST.length; ST.R[i].key != key; i--);
////	return i;
////}
//
////int Search_Bin(SSTable ST, Keytype key)                   //折半查找非递归算法
////{
////	int left = 1;
////	int right = ST.length;
////	while (left <= right)
////	{
////		int mid = (left + right) / 2;
////		if (ST.R[mid].key == key)                         //找到待查元素
////			return mid;
////		else if (key < ST.R[mid].key)                     //缩小查找区间
////			right = mid - 1;                                       //继续在前半区间进行查找
////		else
////			left = mid + 1;                                       //继续在后半区间进行查找
////	}
////	return 0;                                                       //顺序表中不存在待查元素
////}
//
////int Search_Bin(SSTable ST, Keytype key, int left, int right)                      //折半查找递归算法
////{
////	if (left > right)
////		return 0;                                                            //查找不到时返回0
////	int mid = (left + right) / 2;
////	if (ST.R[mid].key == key)
////		return mid;
////	else if (ST.R[mid].key > key)
////		Search_Bin(ST, key, left, mid - 1);                        //递归，在前半区进行查找
////	else
////		Search_Bin(ST, key, mid + 1, right);                   //递归，在后半区进行查找
////}
/*---------------------------线性表的查找----------------------------------*/
#include<stdio.h>

typedef int KeyType;
typedef char InfoType;
typedef struct
{
	KeyType key;                                    //关键字项
	InfoType otherinfo;                          //其他数据域
}ElemType;
typedef struct BSTNode
{
	ElemType data;                               //数据域
	struct BSTNode *lchild, *rchild;       //左右孩子指针
}BSTNode,*BSTree;

BSTree SearchBST(BSTree T, KeyType key)                 //二叉排序树递归查找
{
	if ((!T) || (key == T->data.key))
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key);                      //在左子树中继续查找
	else
		return SearchBST(T->rchild, key);                     //在右子树中继续查找
}
int main()
{

}