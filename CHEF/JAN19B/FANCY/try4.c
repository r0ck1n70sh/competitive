#include <stdio.h>
#include <string.h>
#define smax 100
#define tmax 50

void check(char a[smax][tmax], int t, char pat[])
{
	int i, j, size;
	size=strlen(a[t]);
	//printf("%d\n", size);

	for(i=0; i<size; i++)
	{
		for(j=0; j<4; j++)
		{
			if(a[t][i]!=pat[j])
				break;
			i++;
		}
		i-=j;
		//printf("%d %d\n",i,j);
		if(j==4)
		{
			printf("Real Fancy\n");
			return;
		}
	}

	printf("regularly fancy\n");
	return;
}

int main()
{
	int t, i;
	char s[smax][tmax], pat[]="not ";

	scanf("%d", &t);

	for(i=-1; i<t; i++)
		gets(s[i]);

	for(i=0; i<t; i++)
		check(s,i,pat);


	return 0;
}
