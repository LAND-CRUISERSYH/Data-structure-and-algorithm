#include<stdio.h>
#define MAXSIZE 10                                //设记录不超过10个

typedef int KeyType;                                 //设关键字为int型
typedef char InfoType;                           //设其他数据项为char型
typedef struct                                          //定义每个数据元素的结构
{               
	KeyType key;                                       //关键字
	InfoType otherinfo;                           //其他数据项
}RedType;
typedef struct                                        //定义顺序表的结构
{
	RedType r[MAXSIZE + 1];                   //存储顺序表的向量，r[0]一般作哨兵或缓冲区
	int length;                                         //顺序表的长度
}SqList;

//void InsertSort(SqList *L)                                 //直接插入排序
//{
//	int i, j;
//	for (i = 2; i <= L->length; i++)
//	{
//		if (L->r[i].key < L->r[i - 1].key)                              //若"<",需将L->r[i]插入有序子表
//		{
//			L->r[0] = L->r[i];                                                //复制为哨兵
//			for (j = i - 1; L->r[0].key < L->r[j].key; j--)
//			{
//				L->r[j + 1] = L->r[j];                                     //记录后移
//			}
//			L->r[j + 1] = L->r[0];                                      //插入正确位置
//		}
//	}
//}

//void BinsertSort(SqList *L)                                     //折半插入排序
//{
//	for (int i = 2; i <= L->length; i++)                    //依次插入第2-第n个元素
//	{
//		L->r[0] = L->r[i];                                              //当前插入元素存到"哨兵"位置
//		int left = 1;
//		int right = i - 1;                                              //采用二分查找法查找插入位置
//		while (left <= right)
//		{
//			int mid = (left + right) / 2;
//			if (L->r[0].key < L->r[mid].key)
//				right = mid - 1;
//			else
//				left = mid + 1;
//		}                                                                 //循环结束，right+1为插入位置
//		for (int j = i - 1; j >= right + 1; j--)
//			L->r[j + 1] = L->r[j];                                    //移动元素
//		L->r[right + 1] = L->r[0];                              //插入到正确位置
//	}
//}

//void ShellInsert(SqList *L, int dk)                       //希尔排序
//{                              //对顺序表L进行一趟增量为dk的Shell排序，dk为步长因子
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
//void ShellSort(SqList *L, int dlta[], int t)       //按增量序列dlta[0...t-1]对顺序表L作希尔排序
//{
//	for (int k = 0; k < t; k++)
//		ShellInsert(L, dlta[k]);                             //一趟增量为dlta[k]的插入排序
//}

//void Bubble_Sort(SqList *L)                           //冒泡排序
//{
//	for (int i = 1; i <= L->length - 1; i++)                 //总共需length-1趟
//	{
//		for (int j = 1; j <= L->length - i; j++)
//		{
//			if (L->r[j + 1].key < L->r[j].key)                      //发生逆序
//			{
//				L->r[0].key = L->r[j].key;                          //交换
//				L->r[j].key = L->r[j + 1].key;
//				L->r[j + 1].key = L->r[0].key;
//			}
//		}
//	}
//}
//
///*一旦某一趟比较时不出现记录交换，说明已经排好序了*/
//void Bubble_Sort2(SqList *L)                           //冒泡排序算法改进
//{
//	int flag = 1;                         //flag作为是否有交换的标记
//	for (int i = 1; i <= L->length - 1&&flag==1; i++)                 //总共需length-1趟
//	{
//	    flag = 0;
//		for (int j = 1; j <= L->length - i; j++)
//		{
//			if (L->r[j + 1].key < L->r[j].key)                      //发生逆序
//			{
//				L->r[0].key = L->r[j].key;                          //交换
//				L->r[j].key = L->r[j + 1].key;
//				L->r[j + 1].key = L->r[0].key;
//				flag = 1;                               //发生交换，flag置为1，若本趟没发生交换，flag保持为0
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
//void QSort(SqList *L, int low, int high)             //对顺序表L快速排序
//{
//	if (low < high)                                            //长度大于1
//	{
//		int pivotloc = Partition(L, low, high);   //将L->r[low...high]一分为二，pivotloc为中心元素排好序的位置
//		QSort(L, low, pivotloc - 1);                     //对低子表递归排序
//		QSort(L, pivotloc + 1, high);                   //对高子表递归排序
//	}
//}

void SelectSort(SqList *L)                                //简单选择排序
{
	for (int i = 1; i < L->length; i++)
	{
		int min = i;
		for (int j = i + 1; j <= L->length; j++)
		{
			if (L->r[j].key < L->r[min].key)
				min = j;                 //记录最小值位置
		}
		if (min != i)
		{
			L->r[0] = L->r[min];         //交换
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
	printf("\n长度为: %d", L.length);
	return 0;
}