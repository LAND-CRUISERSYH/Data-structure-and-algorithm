#include<stdio.h>
#define MAXSIZE 10                                //���¼������10��

typedef int KeyType;                                 //��ؼ���Ϊint��
typedef char InfoType;                           //������������Ϊchar��
typedef struct                                          //����ÿ������Ԫ�صĽṹ
{               
	KeyType key;                                       //�ؼ���
	InfoType otherinfo;                           //����������
}RedType;
typedef struct                                        //����˳���Ľṹ
{
	RedType r[MAXSIZE + 1];                   //�洢˳����������r[0]һ�����ڱ��򻺳���
	int length;                                         //˳���ĳ���
}SqList;

//void InsertSort(SqList *L)                                 //ֱ�Ӳ�������
//{
//	int i, j;
//	for (i = 2; i <= L->length; i++)
//	{
//		if (L->r[i].key < L->r[i - 1].key)                              //��"<",�轫L->r[i]���������ӱ�
//		{
//			L->r[0] = L->r[i];                                                //����Ϊ�ڱ�
//			for (j = i - 1; L->r[0].key < L->r[j].key; j--)
//			{
//				L->r[j + 1] = L->r[j];                                     //��¼����
//			}
//			L->r[j + 1] = L->r[0];                                      //������ȷλ��
//		}
//	}
//}

//void BinsertSort(SqList *L)                                     //�۰��������
//{
//	for (int i = 2; i <= L->length; i++)                    //���β����2-��n��Ԫ��
//	{
//		L->r[0] = L->r[i];                                              //��ǰ����Ԫ�ش浽"�ڱ�"λ��
//		int left = 1;
//		int right = i - 1;                                              //���ö��ֲ��ҷ����Ҳ���λ��
//		while (left <= right)
//		{
//			int mid = (left + right) / 2;
//			if (L->r[0].key < L->r[mid].key)
//				right = mid - 1;
//			else
//				left = mid + 1;
//		}                                                                 //ѭ��������right+1Ϊ����λ��
//		for (int j = i - 1; j >= right + 1; j--)
//			L->r[j + 1] = L->r[j];                                    //�ƶ�Ԫ��
//		L->r[right + 1] = L->r[0];                              //���뵽��ȷλ��
//	}
//}

//void ShellInsert(SqList *L, int dk)                       //ϣ������
//{                              //��˳���L����һ������Ϊdk��Shell����dkΪ��������
//	int i, j;
//	for (i = dk + 1; i <= L->length; i++)
//	{
//		if (L->r[i].key < L->r[i - dk].key)
//		{
//			L->r[0] = L->r[i];
//			for (j = i - dk; j > 0 && (L->r[0].key < L->r[j].key); j = j - dk)
//				L->r[j + dk] = L->r[j];
//			L->r[j + dk] = L->r[0];
//		}
//	}
//}
//
//void ShellSort(SqList *L, int dlta[], int t)       //����������dlta[0...t-1]��˳���L��ϣ������
//{
//	for (int k = 0; k < t; k++)
//		ShellInsert(L, dlta[k]);                             //һ������Ϊdlta[k]�Ĳ�������
//}

//void Bubble_Sort(SqList *L)                           //ð������
//{
//	for (int i = 1; i <= L->length - 1; i++)                 //�ܹ���length-1��
//	{
//		for (int j = 1; j <= L->length - i; j++)
//		{
//			if (L->r[j + 1].key < L->r[j].key)                      //��������
//			{
//				L->r[0].key = L->r[j].key;                          //����
//				L->r[j].key = L->r[j + 1].key;
//				L->r[j + 1].key = L->r[0].key;
//			}
//		}
//	}
//}
//
///*һ��ĳһ�˱Ƚ�ʱ�����ּ�¼������˵���Ѿ��ź�����*/
//void Bubble_Sort2(SqList *L)                           //ð�������㷨�Ľ�
//{
//	int flag = 1;                         //flag��Ϊ�Ƿ��н����ı��
//	for (int i = 1; i <= L->length - 1&&flag==1; i++)                 //�ܹ���length-1��
//	{
//	    flag = 0;
//		for (int j = 1; j <= L->length - i; j++)
//		{
//			if (L->r[j + 1].key < L->r[j].key)                      //��������
//			{
//				L->r[0].key = L->r[j].key;                          //����
//				L->r[j].key = L->r[j + 1].key;
//				L->r[j + 1].key = L->r[0].key;
//				flag = 1;                               //����������flag��Ϊ1��������û����������flag����Ϊ0
//			}
//		}
//	}
//}

//void sort(int *arr,int length)
//{
//	int temp;
//	for (int i = 0; i < length - 1; i++)
//	{
//		for (int j = 0; j < length - i - 1; j++)
//		{
//			if (arr[j + 1] < arr[j])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}

//int Partition(SqList *L, int low, int high)
//{
//	L->r[0] = L->r[low];
//	KeyType pivotkey = L->r[low].key;
//	while (low < high)
//	{
//		while (low < high&&L->r[high].key >= pivotkey)
//			high--;
//		L->r[low] = L->r[high];
//		while (low < high&&L->r[low].key <= pivotkey)
//			low++;
//		L->r[high] = L->r[low];
//	}
//	L->r[low] = L->r[0];
//	return low;
//}
//
//
//void QSort(SqList *L, int low, int high)             //��˳���L��������
//{
//	if (low < high)                                            //���ȴ���1
//	{
//		int pivotloc = Partition(L, low, high);   //��L->r[low...high]һ��Ϊ����pivotlocΪ����Ԫ���ź����λ��
//		QSort(L, low, pivotloc - 1);                     //�Ե��ӱ�ݹ�����
//		QSort(L, pivotloc + 1, high);                   //�Ը��ӱ�ݹ�����
//	}
//}

void SelectSort(SqList *L)                                //��ѡ������
{
	for (int i = 1; i < L->length; i++)
	{
		int min = i;
		for (int j = i + 1; j <= L->length; j++)
		{
			if (L->r[j].key < L->r[min].key)
				min = j;                 //��¼��Сֵλ��
		}
		if (min != i)
		{
			L->r[0] = L->r[min];         //����
			L->r[min] = L->r[i];
			L->r[i] = L->r[0];
		}
	}
}

int main()
{
	SqList L;
	int arr[3] = { 5,3,1 };
	for (int i = 1; i <= MAXSIZE; i++)
	{
		scanf("%d", &L.r[i].key);
	}
	L.length = sizeof(L.r) / sizeof(RedType) - 1;
	//InsertSort(&L);
	//BinsertSort(&L);
	//ShellSort(&L, arr, 3);
	//Bubble_Sort(&L);
	//QSort(&L, 1, 10);
	SelectSort(&L);
	for (int i = 1; i <= MAXSIZE; i++)
	{
		printf("%d ", L.r[i].key);
	}
	printf("\n����Ϊ: %d", L.length);
	return 0;
}