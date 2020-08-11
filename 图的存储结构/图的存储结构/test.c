#include<stdio.h>

#define MVNum 100                                //最大顶点数     
#define MaxInt 32767                            //表示极大值，即∞

typedef char VerTexType;                         //设顶点的数据类型为字符型
typedef int ArcType;								//假设边的权值类型为整型
typedef struct
{
	VerTexType vexs[MVNum];                 //顶点表
	ArcType arcs[MVNum][MVNum];       //邻接矩阵
	int vexnum, arcnum;                        //图的当前顶点数和边数
}AMGraph;

int LocateVex(AMGraph *G, VerTexType u)    //在图G中查找顶点u，存在则返回顶点表中的下标，否则返回-1
{
	for (int i = 0; i < G->vexnum; i++)
	{
		if (u == G->vexs[i])
			return i;
	}
	return -1;
}

void CreateUDN(AMGraph *G)                        //采用邻接矩阵表示法创建无向网
{
	printf("请输入顶点数: ");                                //输入顶点数
	scanf("%d", &G->vexnum);
	printf("请输入边数: ");                                  //输入总边数
	scanf("%d", &G->arcnum);
	for (int i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vexs[i]);                      //依次输入点的信息
	}
	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j] = MaxInt;                      //边的权值均置为极大值
		}
	}
	for (int k = 0; i < G->arcnum; k++)         //构造邻接矩阵
	{
		VerTexType v1, v2;              
		ArcType w;
		printf("请输入一条边所依附的两个顶点: ");
		scanf("%c %c", &v1, &v2);                               //输入一条边所依附的顶点
		printf("\n请输入边的权值: ");
		scanf("%d", &w);                                      //输入边的权值
		putchar('\n');
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);                              //确定v1和v2在G中的位置
		G->arcs[i][j] = w;                                         //边的权值置为w
		G->arcs[j][i] = G->arcs[i][j];                         //对应对称权值也设为w
	}
}

int main()
{

}