//#include<stdio.h>
//
//#define MVNnum 100
//
//typedef char VerTexType;
//typedef int ArcType;
//
//typedef struct                                           //�ڽӾ������Ͷ���
//{
//	VerTexType vexs[MVNnum];
//	ArcType arcs[MVNnum][MVNnum];
//	int vexnum, arcnum;
//}AMGraph;
//
//
//int LocateVex(AMGraph *G, VerTexType u)      //��ͼG�в��Ҷ���u
//{
//	for (int i = 0; i < G->vexnum; i++)
//	{
//		if (u == G->vexs[i])
//			return i;
//	}
//	return -1;
//}
//
//void CreateUDN(AMGraph *G)                //�����ڽӾ����ʾ����������ͼ
//{
//	printf("�������ܶ�����: ");
//	scanf("%d", &G->vexnum);
//	printf("�������ܱ���: ");
//	scanf("%d", &G->arcnum);
//	for (int i = 0; i < G->vexnum; i++)
//	{
//		scanf("%c", &G->vexs[i]);
//	}
//	for (int i = 0; i < G->vexnum; i++)
//	{
//		for (int j = 0; j < G->vexnum; j++)
//		{
//			G->arcs[i][j] = 0;
//		}
//	}
//	for (int k = 0; k < G->arcnum; k++)
//	{
//		VerTexType v1, v2;
//		printf("������һ��������������������: ");
//		scanf("%c %c", &v1, &v2);
//		int i = LocateVex(G, v1);
//		int j = LocateVex(G, v2);
//		G->arcs[i][j] = 1;
//		G->arcs[j][i] = G->arcs[i][j];
//	}
//}
//
//
//void DFS(AMGraph G,int *visited, int v)                       //ͼGΪ�ڽӾ�������
//{
//	printf("%c", G.vexs[v]);                                           //vΪ��ʼ����
//	visited[v] = 1;                                                        //����������v��λ����Ϊ1
//	for (int w = 0; w < G.vexnum; w++)              //���μ���ڽӾ���v���ڵ���
//	{
//		if ((G.arcs[v][w] != 0) && (!visited[w]))
//			DFS(G,visited,w);                                      //w��v���ڽӵ㣬���wδ���ʣ���ݹ����DFS
//	}
//}
//
//void BFS(AMGraph G, int *visited, int v)                       //��������ȷǵݹ������ͨͼG
//{
//	printf("%c", G.vexs[v]);                                         //���ʵ�v������
//	visited[v] = 1;                                                        //����������v��λ����Ϊ1
//	InitQueue(Q);                                                         //��������Q��ʼ���ÿ�
//	EnQueue(Q, v);                                                      //v���
//	while (!QueueEmpty(Q))                                         //���зǿ�
//	{
//		DeQueue(Q,u);                                                     //��ͷԪ�س��Ӳ���Ϊu
//		for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
//		{
//			if (!visited[w]) {                                   //wΪu����δ���ʵ��ڽӶ���
//				printf("%c", w);                                       
//				visited[w] = 1;
//				EnQueue(Q, w);                                       //w���
//			}
//		}
//	}
//}
/*-----------------ͼ��������ȱ�����������ȱ���---------------*/

int main()
{
	return 0;
}