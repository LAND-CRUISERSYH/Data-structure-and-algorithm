#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef int Datatype;
typedef struct Stack
{
	Datatype *base;                         //’ªµ◊÷∏’Î
	Datatype *top;							//’ª∂•÷∏’Î
	int stacksize;							//’ªø…”√µƒ◊Ó¥Û»›¡ø
}SqStack;

void InitStack(SqStack *p);                  //À≥–Ú’ªµƒ≥ı ºªØ
int IsEmpty(SqStack *p);                     //≈–∂œ’ª «∑ÒŒ™ø’
int GetLength(SqStack *p);                 //«ÛÀ≥–Ú’ª≥§∂»
void ClearStack(SqStack *p);             //«Âø’À≥–Ú’ª
void DestroyStack(SqStack *p);        //œ˙ªŸÀ≥–Ú’ª
void PushStack(SqStack *p, Datatype x);          //»Î’ª

int main()
{
	return 0;
}

void InitStack(SqStack *p)                  //À≥–Ú’ªµƒ≥ı ºªØ
{
	p->base = (Datatype*)malloc(SIZE * sizeof(Datatype));
	if (!p->base)                                          
	{
		printf("ƒ⁄¥Ê∑÷≈‰ ß∞‹!\n");                //¥Ê¥¢∑÷≈‰ ß∞‹
		return;
	}
	p->top = p->base;                         //’ª∂•÷∏’Îµ»”⁄’ªµ◊÷∏’Î
	p->stacksize = SIZE;
}

int IsEmpty(SqStack *p)                     //≈–∂œ’ª «∑ÒŒ™ø’
{
	if (p->base == p->top)           //»Ù’ªŒ™ø’∑µªÿ1
		return 1;
	return 0;									//≤ªŒ™ø’∑µªÿ0
}

int GetLength(SqStack *p)                 //«ÛÀ≥–Ú’ª≥§∂»
{
	return p->top - p->base;             //’ª∂•÷∏’Î∫Õ’ªµ◊÷∏’Îµƒ≤Ó÷µ
}

void ClearStack(SqStack *p)             //«Âø’À≥–Ú’ª
{
	if (p->base)                                   //»Áπ˚’ª¥Ê‘⁄£¨Ω´’ª∂•÷∏’Î÷∏œÚ’ªµ◊
		p->top = p->base; 	
}

void DestroyStack(SqStack *p)        //œ˙ªŸÀ≥–Ú’ª
{
	if (p->base)                                     //≈–∂œ’ª «∑Ò¥Ê‘⁄
	{ 
		free(p->base);                          //œ˙ªŸÀ≥–Ú’ª
		p->stacksize = 0;
		p->base = p->top = NULL;
	}
}

void PushStack(SqStack *p, Datatype x)          //»Î’ª
{
	if (p->top - p->base == p->stacksize)         //≈–∂œ «∑Ò’ª¬˙
	{
		printf("’ª¬˙!\n");
		return;
	}
	*(p->top) = x;                          //‘™Àÿ»Î’ª
	p->top++;                             //’ª∂•÷∏’Î+1
}       