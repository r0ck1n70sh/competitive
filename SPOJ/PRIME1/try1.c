#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define maxline 100000

bool prime_check(int value)
{
	unsigned int num=2;
	while(num<=sqrt(value))
	{
		if((value%num)==0)
			return false;
		num++;
	}

	if(value!=1)
		return true;
	else
		return false;
}

int main()
{
	unsigned int t, lower[maxline], upper[maxline];
	unsigned int num, i;

	scanf("%u", &t);

	for(i=0; i<t; i++)
	{
		scanf("%u%u", &lower[i], &upper[i]);
	}

	for(i=0; i<t; i++)
	{
		num=lower[i];
		while(num<=upper[i])
		{
			if(prime_check(num))
				printf("%d\n", num);
			num++;
		}
		printf("\n");
	}

	return 0;
}
