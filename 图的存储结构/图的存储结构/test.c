#include<stdio.h>

#define MVNum 100                                //��󶥵���     
#define MaxInt 32767                            //��ʾ����ֵ������

typedef char VerTexType;                         //�趥�����������Ϊ�ַ���
typedef int ArcType;								//����ߵ�Ȩֵ����Ϊ����
typedef struct
{
	VerTexType vexs[MVNum];                 //�����
	ArcType arcs[MVNum][MVNum];       //�ڽӾ���
	int vexnum, arcnum;                        //ͼ�ĵ�ǰ�������ͱ���
}AMGraph;

int LocateVex(AMGraph *G, VerTexType u)    //��ͼG�в��Ҷ���u�������򷵻ض�����е��±꣬���򷵻�-1
{
	for (int i = 0; i < G->vexnum; i++)
	{
		if (u == G->vexs[i])
			return i;
	}
	return -1;
}

void CreateUDN(AMGraph *G)                        //�����ڽӾ����ʾ������������
{
	printf("�����붥����: ");                                //���붥����
	scanf("%d", &G->vexnum);
	printf("���������: ");                                  //�����ܱ���
	scanf("%d", &G->arcnum);
	for (int i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vexs[i]);                      //������������Ϣ
	}
	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j] = MaxInt;                      //�ߵ�Ȩֵ����Ϊ����ֵ
		}
	}
	for (int k = 0; i < G->arcnum; k++)         //�����ڽӾ���
	{
		VerTexType v1, v2;              
		ArcType w;
		printf("������һ��������������������: ");
		scanf("%c %c", &v1, &v2);                               //����һ�����������Ķ���
		printf("\n������ߵ�Ȩֵ: ");
		scanf("%d", &w);                                      //����ߵ�Ȩֵ
		putchar('\n');
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);                              //ȷ��v1��v2��G�е�λ��
		G->arcs[i][j] = w;                                         //�ߵ�Ȩֵ��Ϊw
		G->arcs[j][i] = G->arcs[i][j];                         //��Ӧ�Գ�ȨֵҲ��Ϊw
	}
}

int main()
{

}