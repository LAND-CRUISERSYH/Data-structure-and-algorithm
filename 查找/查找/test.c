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
////int Search_Seq(SSTable ST, Keytype key)     //˳�����
////{
////	for (int i = ST.length; i >= 1; i--)
////	{
////		if (ST.R[i].key == key)
////			return i;
////	}
////	return 0;
////}
//
////int Search_Seq(SSTable ST, Keytype key)            //˳�����----��һ����ʽ
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
////int Search_Seq(SSTable ST, Keytype key)                  //˳�����---���ڱ�����ʽ
////{
////	ST.R[0].key = key;
////	int i = ST.length;
////	for (i = ST.length; ST.R[i].key != key; i--);
////	return i;
////}
//
////int Search_Bin(SSTable ST, Keytype key)                   //�۰���ҷǵݹ��㷨
////{
////	int left = 1;
////	int right = ST.length;
////	while (left <= right)
////	{
////		int mid = (left + right) / 2;
////		if (ST.R[mid].key == key)                         //�ҵ�����Ԫ��
////			return mid;
////		else if (key < ST.R[mid].key)                     //��С��������
////			right = mid - 1;                                       //������ǰ��������в���
////		else
////			left = mid + 1;                                       //�����ں��������в���
////	}
////	return 0;                                                       //˳����в����ڴ���Ԫ��
////}
//
////int Search_Bin(SSTable ST, Keytype key, int left, int right)                      //�۰���ҵݹ��㷨
////{
////	if (left > right)
////		return 0;                                                            //���Ҳ���ʱ����0
////	int mid = (left + right) / 2;
////	if (ST.R[mid].key == key)
////		return mid;
////	else if (ST.R[mid].key > key)
////		Search_Bin(ST, key, left, mid - 1);                        //�ݹ飬��ǰ�������в���
////	else
////		Search_Bin(ST, key, mid + 1, right);                   //�ݹ飬�ں�������в���
////}
/*---------------------------���Ա�Ĳ���----------------------------------*/
#include<stdio.h>

typedef int KeyType;
typedef char InfoType;
typedef struct
{
	KeyType key;                                    //�ؼ�����
	InfoType otherinfo;                          //����������
}ElemType;
typedef struct BSTNode
{
	ElemType data;                               //������
	struct BSTNode *lchild, *rchild;       //���Һ���ָ��
}BSTNode,*BSTree;

BSTree SearchBST(BSTree T, KeyType key)                 //�����������ݹ����
{
	if ((!T) || (key == T->data.key))
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key);                      //���������м�������
	else
		return SearchBST(T->rchild, key);                     //���������м�������
}
int main()
{

}