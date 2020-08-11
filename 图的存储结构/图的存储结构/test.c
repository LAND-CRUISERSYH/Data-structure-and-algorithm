//#include<stdio.h>
//
//#define MVNum 100                                //最大顶点数     
//#define MaxInt 32767                            //表示极大值，即∞
//
//typedef char VerTexType;                         //设顶点的数据类型为字符型
//typedef int ArcType;								//假设边的权值类型为整型
//typedef struct
//{
//	VerTexType vexs[MVNum];                 //顶点表
//	ArcType arcs[MVNum][MVNum];       //邻接矩阵
//	int vexnum, arcnum;                        //图的当前顶点数和边数
//}AMGraph;
//
//int LocateVex(AMGraph *G, VerTexType u)    //在图G中查找顶点u，存在则返回顶点表中的下标，否则返回-1
//{
//	for (int i = 0; i < G->vexnum; i++)
//	{
//		if (u == G->vexs[i])
//			return i;
//	}
//	return -1;
//}
//
//void CreateUDN(AMGraph *G)                        //采用邻接矩阵表示法创建无向网
//{
//	printf("请输入顶点数: ");                                //输入顶点数
//	scanf("%d", &G->vexnum);
//	printf("请输入边数: ");                                  //输入总边数
//	scanf("%d", &G->arcnum);
//	for (int i = 0; i < G->vexnum; i++)
//	{
//		scanf("%c", &G->vexs[i]);                      //依次输入点的信息
//	}
//	for (int i = 0; i < G->vexnum; i++)
//	{
//		for (int j = 0; j < G->vexnum; j++)
//		{
//			G->arcs[i][j] = MaxInt;                      //边的权值均置为极大值
//		}
//	}
//	for (int k = 0; k < G->arcnum; k++)         //构造邻接矩阵
//	{
//		VerTexType v1, v2;              
//		ArcType w;
//		printf("请输入一条边所依附的两个顶点: ");
//		scanf("%c %c", &v1, &v2);                               //输入一条边所依附的顶点
//		printf("\n请输入边的权值: ");
//		scanf("%d", &w);                                      //输入边的权值
//		putchar('\n');
//		int i = LocateVex(G, v1);
//		int j = LocateVex(G, v2);                              //确定v1和v2在G中的位置
//		G->arcs[i][j] = w;                                         //边的权值置为w
//		G->arcs[j][i] = G->arcs[i][j];                         //对应对称权值也设为w
//	}
//}
/*---------------------------------图的邻接矩阵表示法--------------------------------*/
/*---------------------------------图的邻接表表示法----------------------------------*/
#include<stdio.h>
#include<stdlib.h>

#define MVNum 100                      //最大顶点数

typedef char VerTexType;            
typedef struct ArcNode                 //边结点
{ 
	int avjvex;                                   //该边所指向的顶点位置
	int info;                                      //和边相关的信息
	struct ArcNode *nextarc;           //指向下一条边的指针
}ArcNode;
typedef struct VNode                      //顶点
{
	VerTexType data;                               //顶点信息
	ArcNode *firstarc;                              //指向第一条依附该顶点的边的指针
}VNode,AdjList[MVNum];                    //AdjList表示邻接表类型
typedef struct                                   //图的结构定义
{
	AdjList vertices;                          //vertices--vertex的复数
	int vexnum, arcnum;                 //图的当前顶点数和边数
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

void CreateUDG(ALGraph *G)                              //采用邻接表表示法，创建无向图G
{
	VerTexType v1, v2;
	int i, j,w;
	printf("请输入总顶点数: ");                                 //输入总顶点数
	scanf("%d", &G->vexnum);
	printf("请输入总边数: ");                                      //输入总边数
	scanf("%d", &G->arcnum);
	for (int i = 0; i < G->vexnum; i++)                       //输入各点，构造表头结点表
	{ 
		scanf("%c", &G->vertices[i].data);                   //输入顶点值
		G->vertices[i].firstarc = NULL;                        //初始化表头结点的指针域
	}
	for (int k = 0; k <(2*G->arcnum); k++)               //输入各边，构造邻接表
	{
		printf("请输入第一个顶点: ");                              //输入一条边依附的第一个顶点
		scanf("%c", &v1);
		printf("请输入第二个顶点: ");                           //输入一条边依附的第二个顶点
		scanf("%c", &v2);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		printf("请输入边的权值: ");
		scanf("%d", &w);
		ArcNode *p1 = (ArcNode*)malloc(sizeof(ArcNode));      //生成一个新的边结点p1
		p1->avjvex = j;                                          //邻接点序号为j
		p1->info = w;                                          //赋权值
		p1->nextarc=G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1;                           //将新结点*p1插入顶点Vi的边表头部
		ArcNode *p2 = (ArcNode*)malloc(sizeof(ArcNode));      //生成一个新的边结点p2
		p2->avjvex = i;                                          //邻接点序号为i
		p2->info = w;                                             //赋权值
		p2->nextarc = G->vertices[j].firstarc;
		G->vertices[j].firstarc = p2;                             //将新结点*p2插入顶点Vj的边边表头部		
	}
}

int main()
{

}