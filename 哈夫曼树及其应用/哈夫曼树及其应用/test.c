#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct                  //结点类型定义
{
	int weight;            //权值
	int parent, lch, rch;              //双亲结点、左孩子及右孩子下标
}HTNode,*HuffmanTree;

void Select(HuffmanTree HT,int n,int *s1,int *s2)
{
	*s1 = *s2 = 0;
	int min1 = INT_MAX;                       //最小值，INT_MAX在<limits.h>中定义
	int min2 = INT_MAX;                       //次小值
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0)                    //筛选没有双亲的最小和次小值下标
		{
			if (HT[i].weight < min1)                //如果比最小值小
			{
				min2 = min1;
				*s2 = *s1;
				min1 = HT[i].weight;
				*s1 = i;
			}
			else if((HT[i].weight >= min1) && (HT[i].weight < min2))        //如果大于等于最小值且小于次小值
			{
				min2 = HT[i].weight;
				*s2 = i;
			}
			else                                           //如果大于次小值则什么也不做
			{
				;
			}
		}
	}
}

void CreatHuffmanTree(HuffmanTree HT, int n)                   //初始化数组并建立哈夫曼树
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;           //数组共2n-1个元素
	int s1, s2;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));             //0号单元不用，HT[m]表示根结点
	for (int i = 1; i <= m; i++)              //将2n-1个元素的parent,lch,rch设置为0
	{
		HT[i].parent = 0;
		HT[i].lch = 0;
		HT[i].rch = 0;
	}
	for (int i = 1; i <= n; i++)                //输入前n个元素的weight值
	{
		scanf("%d", &HT[i].weight);
	}
	for (int i = n + 1; i <= m; i++)              //合并产生n-1个结点----构造Huffman树
	{
		Select(HT, i - 1, &s1, &s2);           //在HT[k](1<=k<=i-1)中选择两个其双亲为0,且权值最小的结点下标存在s1，s2中
		HT[s1].parent = i;                         //从F中删除s1
		HT[s2].parent = i;                         //从F中删除s1
		HT[i].lch = s1;
		HT[i].rch = s2;                             //s1,s2分别作为i的左右孩子
		HT[i].weight = HT[s1].weight + HT[s2].weight;           //i的权值为左右孩子权值之和
	}
}

int main()
{
	return 0;
}