#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct                  //������Ͷ���
{
	int weight;            //Ȩֵ
	int parent, lch, rch;              //˫�׽�㡢���Ӽ��Һ����±�
}HTNode,*HuffmanTree;

void Select(HuffmanTree HT,int n,int *s1,int *s2)
{
	*s1 = *s2 = 0;
	int min1 = INT_MAX;                       //��Сֵ��INT_MAX��<limits.h>�ж���
	int min2 = INT_MAX;                       //��Сֵ
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0)                    //ɸѡû��˫�׵���С�ʹ�Сֵ�±�
		{
			if (HT[i].weight < min1)                //�������СֵС
			{
				min2 = min1;
				*s2 = *s1;
				min1 = HT[i].weight;
				*s1 = i;
			}
			else if((HT[i].weight >= min1) && (HT[i].weight < min2))        //������ڵ�����Сֵ��С�ڴ�Сֵ
			{
				min2 = HT[i].weight;
				*s2 = i;
			}
			else                                           //������ڴ�Сֵ��ʲôҲ����
			{
				;
			}
		}
	}
}

void CreatHuffmanTree(HuffmanTree HT, int n)                   //��ʼ�����鲢������������
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;           //���鹲2n-1��Ԫ��
	int s1, s2;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));             //0�ŵ�Ԫ���ã�HT[m]��ʾ�����
	for (int i = 1; i <= m; i++)              //��2n-1��Ԫ�ص�parent,lch,rch����Ϊ0
	{
		HT[i].parent = 0;
		HT[i].lch = 0;
		HT[i].rch = 0;
	}
	for (int i = 1; i <= n; i++)                //����ǰn��Ԫ�ص�weightֵ
	{
		scanf("%d", &HT[i].weight);
	}
	for (int i = n + 1; i <= m; i++)              //�ϲ�����n-1�����----����Huffman��
	{
		Select(HT, i - 1, &s1, &s2);           //��HT[k](1<=k<=i-1)��ѡ��������˫��Ϊ0,��Ȩֵ��С�Ľ���±����s1��s2��
		HT[s1].parent = i;                         //��F��ɾ��s1
		HT[s2].parent = i;                         //��F��ɾ��s1
		HT[i].lch = s1;
		HT[i].rch = s2;                             //s1,s2�ֱ���Ϊi�����Һ���
		HT[i].weight = HT[s1].weight + HT[s2].weight;           //i��ȨֵΪ���Һ���Ȩֵ֮��
	}
}

int main()
{
	return 0;
}