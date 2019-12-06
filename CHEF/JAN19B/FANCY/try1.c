#include <stdio.h>
#define tmax 50
#define smax 100

void inputstr(int n, char in[tmax][smax])
{
	int i=0;
	char c='1';
	while(c!='\0')
	{
		scanf("%c", c);
		in[n][i]= c;
		i++;
	}
}

void printstr(int n, char out[tmax][smax])
{
	int i=0;
	char c='a';
	while(c!='\0')
	{
		c=out[n][i];
		printf("%c", c);
		i++;
	}
}

int main()
{
	int t;
	int i;
 	char s[tmax][smax];

	scanf("%d", &t);
	printf("%d", t);

	for(i=0; i<t; i++)
	{
		inputstr(i, s);
	}

	for(i=0; i<t; i++)
	{
		printstr(i, s);
	}

	return 0;
}
