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

//int Search_Seq(SSTable ST, Keytype key)     //���ɹ�������λ����Ϣ�����򷵻�0
//{
//	for (int i = ST.length; i >= 1; i--)
//	{
//		if (ST.R[i].key == key)
//			return i;
//	}
//	return 0;
//}

//int Search_Seq(SSTable ST, Keytype key)            //��һ����ʽ
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

int Search_Seq(SSTable ST, Keytype key)                  //���ڱ�����ʽ
{
	ST.R[0].key = key;
	int i = ST.length;
	for (i = ST.length; ST.R[i].key != key; i--);
	return i;
}

int main()
{

}