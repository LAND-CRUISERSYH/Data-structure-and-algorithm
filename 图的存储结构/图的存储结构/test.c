//#include<stdio.h>
//
//#define MVNum 100                                //��󶥵���     
//#define MaxInt 32767                            //��ʾ����ֵ������
//
//typedef char VerTexType;                         //�趥�����������Ϊ�ַ���
//typedef int ArcType;								//����ߵ�Ȩֵ����Ϊ����
//typedef struct
//{
//	VerTexType vexs[MVNum];                 //�����
//	ArcType arcs[MVNum][MVNum];       //�ڽӾ���
//	int vexnum, arcnum;                        //ͼ�ĵ�ǰ�������ͱ���
//}AMGraph;
//
//int LocateVex(AMGraph *G, VerTexType u)    //��ͼG�в��Ҷ���u�������򷵻ض�����е��±꣬���򷵻�-1
//{
//	for (int i = 0; i < G->vexnum; i++)
//	{
//		if (u == G->vexs[i])
//			return i;
//	}
//	return -1;
//}
//
//void CreateUDN(AMGraph *G)                        //�����ڽӾ����ʾ������������
//{
//	printf("�����붥����: ");                                //���붥����
//	scanf("%d", &G->vexnum);
//	printf("���������: ");                                  //�����ܱ���
//	scanf("%d", &G->arcnum);
//	for (int i = 0; i < G->vexnum; i++)
//	{
//		scanf("%c", &G->vexs[i]);                      //������������Ϣ
//	}
//	for (int i = 0; i < G->vexnum; i++)
//	{
//		for (int j = 0; j < G->vexnum; j++)
//		{
//			G->arcs[i][j] = MaxInt;                      //�ߵ�Ȩֵ����Ϊ����ֵ
//		}
//	}
//	for (int k = 0; k < G->arcnum; k++)         //�����ڽӾ���
//	{
//		VerTexType v1, v2;              
//		ArcType w;
//		printf("������һ��������������������: ");
//		scanf("%c %c", &v1, &v2);                               //����һ�����������Ķ���
//		printf("\n������ߵ�Ȩֵ: ");
//		scanf("%d", &w);                                      //����ߵ�Ȩֵ
//		putchar('\n');
//		int i = LocateVex(G, v1);
//		int j = LocateVex(G, v2);                              //ȷ��v1��v2��G�е�λ��
//		G->arcs[i][j] = w;                                         //�ߵ�Ȩֵ��Ϊw
//		G->arcs[j][i] = G->arcs[i][j];                         //��Ӧ�Գ�ȨֵҲ��Ϊw
//	}
//}
/*---------------------------------ͼ���ڽӾ����ʾ��--------------------------------*/
/*---------------------------------ͼ���ڽӱ��ʾ��----------------------------------*/
#include<stdio.h>
#include<stdlib.h>

#define MVNum 100                      //��󶥵���

typedef char VerTexType;            
typedef struct ArcNode                 //�߽��
{ 
	int avjvex;                                   //�ñ���ָ��Ķ���λ��
	int info;                                      //�ͱ���ص���Ϣ
	struct ArcNode *nextarc;           //ָ����һ���ߵ�ָ��
}ArcNode;
typedef struct VNode                      //����
{
	VerTexType data;                               //������Ϣ
	ArcNode *firstarc;                              //ָ���һ�������ö���ıߵ�ָ��
}VNode,AdjList[MVNum];                    //AdjList��ʾ�ڽӱ�����
typedef struct                                   //ͼ�Ľṹ����
{
	AdjList vertices;                          //vertices--vertex�ĸ���
	int vexnum, arcnum;                 //ͼ�ĵ�ǰ�������ͱ���
}ALGraph;

int LocateVex(ALGraph *G, VerTexType u)
{
	for (int z = 0; z < G->vexnum; z++)
	{
		if (G->vertices[z].data == u)
			return z;
	}
	return -1;
}

void CreateUDG(ALGraph *G)                              //�����ڽӱ��ʾ������������ͼG
{
	VerTexType v1, v2;
	int i, j,w;
	printf("�������ܶ�����: ");                                 //�����ܶ�����
	scanf("%d", &G->vexnum);
	printf("�������ܱ���: ");                                      //�����ܱ���
	scanf("%d", &G->arcnum);
	for (int i = 0; i < G->vexnum; i++)                       //������㣬�����ͷ����
	{ 
		scanf("%c", &G->vertices[i].data);                   //���붥��ֵ
		G->vertices[i].firstarc = NULL;                        //��ʼ����ͷ����ָ����
	}
	for (int k = 0; k <(2*G->arcnum); k++)               //������ߣ������ڽӱ�
	{
		printf("�������һ������: ");                              //����һ���������ĵ�һ������
		scanf("%c", &v1);
		printf("������ڶ�������: ");                           //����һ���������ĵڶ�������
		scanf("%c", &v2);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		printf("������ߵ�Ȩֵ: ");
		scanf("%d", &w);
		ArcNode *p1 = (ArcNode*)malloc(sizeof(ArcNode));      //����һ���µı߽��p1
		p1->avjvex = j;                                          //�ڽӵ����Ϊj
		p1->info = w;                                          //��Ȩֵ
		p1->nextarc=G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1;                           //���½��*p1���붥��Vi�ı߱�ͷ��
		ArcNode *p2 = (ArcNode*)malloc(sizeof(ArcNode));      //����һ���µı߽��p2
		p2->avjvex = i;                                          //�ڽӵ����Ϊi
		p2->info = w;                                             //��Ȩֵ
		p2->nextarc = G->vertices[j].firstarc;
		G->vertices[j].firstarc = p2;                             //���½��*p2���붥��Vj�ı߱߱�ͷ��		
	}
}

int main()
{

}