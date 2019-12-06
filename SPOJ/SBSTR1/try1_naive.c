#include <stdio.h>

void str_input(char *a, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		scanf("%c", a+i)
	}
}

int match(char *str, char *pat)
{
	int i, j;
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			if(str[i]!=pat[j])
				break;
			i++;
		}

		i-=j;
		if(j==4)
			return 1;
	}

	return 0;
}

int main()
{
	int i, out, max=2;
	char A[max][10];
	char B[max][5];

	for(i=0; i<max; i++)
	{
		str_input(A+(i*10), 10);
		str_input(B+(i*5), 5);
	}

	for(i=0; i<max; i++)
	{
		out= match(A+(i*10), B+(i*5));
		printf("%d\n", out)
	}

	return 0;
}
