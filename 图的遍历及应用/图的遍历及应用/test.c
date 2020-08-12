#include<stdio.h>

#define MVNnum 100

typedef char VerTexType;
typedef int ArcType;

typedef struct                                           //邻接矩阵类型定义
{
	VerTexType vexs[MVNnum];
	ArcType arcs[MVNnum][MVNnum];
	int vexnum, arcnum;
}AMGraph;


int LocateVex(AMGraph *G, VerTexType u)      //在图G中查找顶点u
{
	for (int i = 0; i < G->vexnum; i++)
	{
		if (u == G->vexs[i])
			return i;
	}
	return -1;
}

void CreateUDN(AMGraph *G)                //采用邻接矩阵表示法创建无向图
{
	printf("请输入总顶点数: ");
	scanf("%d", &G->vexnum);
	printf("请输入总边数: ");
	scanf("%d", &G->arcnum);
	for (int i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vexs[i]);
	}
	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j] = 0;
		}
	}
	for (int k = 0; k < G->arcnum; k++)
	{
		VerTexType v1, v2;
		printf("请输入一条边所依附的两个顶点: ");
		scanf("%c %c", &v1, &v2);
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		G->arcs[i][j] = 1;
		G->arcs[j][i] = G->arcs[i][j];
	}
}


void DFS(AMGraph G,int *visited, int v)                       //图G为邻接矩阵类型
{
	printf("%c", G.vexs[v]);                                           //v为起始顶点
	visited[v] = 1;                                                        //将辅助数组v的位置设为1
	for (int w = 0; w < G.vexnum; w++)              //依次检查邻接矩阵v所在的行
	{
		if ((G.arcs[v][w] != 0) && (!visited[w]))
			DFS(G,visited,w);                                      //w是v的邻接点，如果w未访问，则递归调用DFS
	}
}

int main()
{
	return 0;
}