#include<stdio.h>
#include<string.h>

#define SIZE 20

typedef struct
{
	char ch[SIZE + 1];                 //存储串的一维数组
	int length;							//串的当前长度
}str;

int Index_BF(str S, str T);            //BF算法

//#define CHUNKSIZE 20
//
//typedef struct Chunk
//{
//	char ch[CHUNKSIZE];                 //存放一个块中的字符
//	struct Chunk *next;                    //指向下一个块
//}Chunk;
//
//typedef struct
//{
//	Chunk *head, *tail;                    //串的头指针和尾指针
//	int length;                                 //串的当前长度
//}LStr;                                           //字符串的块链结构

int main()
{
	str S, T;
	printf("请输入第一个字符串: ");
	gets(S.ch);
	getchar();
	printf("请输入第二个字符串: ");
	gets(T.ch);
	getchar();
	S.length = strlen(S.ch) - 1;
	T.length = strlen(T.ch) - 1;
	printf("位置下标为: %d\n", Index_BF(S, T));
	return 0;
}

int Index_BF(str S, str T)            //BF算法
{
	int i = 1, j = 1;                       //从下标1开始存储字符串，下标0空出来
	while (i <= S.length&&j <= T.length)
	{
		if (S.ch[i] == T.ch[j])               //主串和子串依次匹配下一个字符
		{
			i++;
			j++;
		}
		else                                    //主串和子串指针回溯重新开始下一次匹配
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length)
		return i - T.length;                     //返回匹配的第一个字符的下标
	else
		return 0;                                     //模式匹配不成功
}
