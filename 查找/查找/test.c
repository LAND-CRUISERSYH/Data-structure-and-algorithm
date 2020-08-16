#include<stdio.h>

typedef int Keytype;
typedef struct
{
	Keytype key;
}ElemType;

typedef struct
{
	ElemType *R;
	int length;
}SSTable;

//int Search_Seq(SSTable ST, Keytype key)     //若成功返回其位置信息，否则返回0
//{
//	for (int i = ST.length; i >= 1; i--)
//	{
//		if (ST.R[i].key == key)
//			return i;
//	}
//	return 0;
//}

//int Search_Seq(SSTable ST, Keytype key)            //另一种形式
//{
//	int i = ST.length;
//	for (i = ST.length; ST.R[i].key != key; i--)
//	{
//		if (i <= 0)
//			break;
//	}
//	if (i > 0)
//		return i;
//	else
//		return 0;
//}

int Search_Seq(SSTable ST, Keytype key)                  //加哨兵的形式
{
	ST.R[0].key = key;
	int i = ST.length;
	for (i = ST.length; ST.R[i].key != key; i--);
	return i;
}

int main()
{

}