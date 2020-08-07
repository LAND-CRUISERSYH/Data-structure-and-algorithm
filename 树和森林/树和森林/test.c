#include<stdio.h>
#include<string.h>

/*#define SIZE 10                             //双亲表示法

typedef char Datatype;
typedef struct PTNode
{
	Datatype ch;
	int parent;             //双亲位置域
}PTNode;           

typedef sturct
{
	PTNode nodes[SIZE];
	int r, n;                              //根结点的位置和结点个数
}PTree;*/
 
/*#define SIZE 10                        //孩子链表

typedef char Datatype;
typedef struct CTNode         //孩子结点结构
{
	int child;                          //孩子的下标
	struct CTNode *next;      //兄弟的地址
}*ChildPtr;

typedef struct                   //双亲结点结构
{
	Datatype data;               //数据域
	ChildPtr fiestchild;         //孩子链表头指针
}CTBox;

typedef struct                    //树结构
{
	CTBox nodes[SIZE];    
	int r, n;                            //根结点的位置和结点数
}ChTree;*/

/*typedef char Datatype;               //孩子兄弟表示法

typedef struct CSNode
{
	Datatype data;                             //数据域
	struct CSNode *firstchild, *nextsibling;          //指向第一个孩子结点和兄弟结点
}CSNode,*CSTree;*/