#include<stdio.h>

#define list 3
#define line 3

void Judge(char board[list][line], char *input, int t, int e)
{
	int a = 0;
	int b = 0;
	int i = 0;
	for (a = 0; a < t; a++)
	{
		for (b = 0; b < e; b++)
		{
			if (board[a][b] != ' ')
				i++;
		}
	}
	if (i = t * e)
		*input = 'T';
	else
		*input = 'F';
}

int main()
{
	char arr[list][line] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	char ch;
	Judge(arr, &ch, list,line);
	printf("ÊÇ·ñÆ½¾Ö: %c\n", ch);
}