//#include<stdio.h>
//#include<stdlib.h>
//#include<limits.h>
//
//
//typedef struct                  //结点类型定义
//{
//	int weight;            //权值
//	int parent, lch, rch;              //双亲结点、左孩子及右孩子下标
//}HTNode,*HuffmanTree;
//
//void Select(HuffmanTree HT,int n,int *s1,int *s2)
//{
//	*s1 = *s2 = 0;
//	int min1 = INT_MAX;                       //最小值，INT_MAX在<limits.h>中定义
//	int min2 = INT_MAX;                       //次小值
//	for (int i = 1; i <= n; i++)
//	{
//		if (HT[i].parent == 0)                    //筛选没有双亲的最小和次小值下标
//		{
//			if (HT[i].weight < min1)                //如果比最小值小
//			{
//				min2 = min1;
//				*s2 = *s1;
//				min1 = HT[i].weight;
//				*s1 = i;
//			}
//			else if((HT[i].weight >= min1) && (HT[i].weight < min2))        //如果大于等于最小值且小于次小值
//			{
//				min2 = HT[i].weight;
//				*s2 = i;
//			}
//			else                                           //如果大于次小值则什么也不做
//			{
//				;
//			}
//		}
//	}
//}
//
//void CreatHuffmanTree(HuffmanTree HT, int n)                   //初始化数组并建立哈夫曼树
//{
//	if (n <= 1)
//		return;
//	int m = 2 * n - 1;           //数组共2n-1个元素
//	int s1, s2;
//	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));             //0号单元不用，HT[m]表示根结点
//	for (int i = 1; i <= m; i++)              //将2n-1个元素的parent,lch,rch设置为0
//	{
//		HT[i].parent = 0;
//		HT[i].lch = 0;
//		HT[i].rch = 0;
//	}
//	for (int i = 1; i <= n; i++)                //输入前n个元素的weight值
//	{
//		scanf("%d", &HT[i].weight);
//	}
//	for (int i = n + 1; i <= m; i++)              //合并产生n-1个结点----构造Huffman树
//	{
//		Select(HT, i - 1, &s1, &s2);           //在HT[k](1<=k<=i-1)中选择两个其双亲为0,且权值最小的结点下标存在s1，s2中
//		HT[s1].parent = i;                         //从F中删除s1
//		HT[s2].parent = i;                         //从F中删除s1
//		HT[i].lch = s1;
//		HT[i].rch = s2;                             //s1,s2分别作为i的左右孩子
//		HT[i].weight = HT[s1].weight + HT[s2].weight;           //i的权值为左右孩子权值之和
//	}
//}
//
//int main()
//{
//	return 0;
//}                                             
/* --------------------------------------------------哈夫曼树--------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>


typedef struct HTnode
{
	int weight;
	int parent, lch, rch;
}HTnode,*HuffmanTree;

typedef char** HuffmanCode;


void Select(HuffmanTree HT, int n, int *s1, int *s2)
{
	*s1 = *s2 = 0;
	int min1 = INT_MAX;
	int min2 = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0)
		{
			if (HT[i].weight < min1)
			{
				min2 = min1;
				*s2 = *s1;
				min1 = HT[i].weight;
				*s1 = i;
			}
			else if ((HT[i].weight > min1) && (HT[i].weight <= min2))
			{
				min2 = HT[i].weight;
				*s2 = i;
			}
			else
			{
				;
			}
		}
	}
}

void CreatHuffmanTree(HuffmanTree HT, int n)
{
	if (n <= 1)
		return;
	int m = 2*n - 1;
	int s1, s2;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTnode));
	for (int i = 1; i <= m; i++)
	{
		HT[i].parent = 0;
		HT[i].lch = 0;
		HT[i].rch = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &HT[i].weight);
	}
	for (int i = n + 1; i <= m; i++)
	{
		Select(HT, i - 1, &s1, &s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lch = s1;
		HT[i].rch = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

void CreateHuffmanCode(HuffmanTree HT, HuffmanCode *HC, int n) //从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
{
	*HC = (char**)malloc((n + 1)*sizeof(char *));                 //分配n个字符编码的头指针
	char *cd = (char *)malloc(n * sizeof(char));                   //分配临时存放编码的动态数组空间
	cd[n - 1] = '\0';                                                       //编码结束符
	for (int i = 1; i <= n; i++)                                     //逐个字符求哈夫曼编码
	{
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0)                                                        //从叶子结点开始向上回溯，直到根结点
		{
			--start;                                                             //回溯一次start向前指一个位置
			if (HT[f].lch == c)                                   //结点c是f的左孩子，则生成代码0
				cd[start] = '0'; 
			else                                                       //结点c是f的右孩子，则生成代码1
				cd[start] = '1';
			c = f;
			f = HT[f].parent;                                         //继续向上回溯
		}                                                                      //求出第i个字符的编码
		(*HC)[i] = (char*)malloc((n - start) * sizeof(char));                //为第一个字符串编码分配空间
		strcpy((*HC)[i], &cd[start]);                          //将求得的编码从临时空间cd复制到HC的当前行中
	}
	free(cd);                      //释放临时空间
}

int main()
{
	return 0;
}