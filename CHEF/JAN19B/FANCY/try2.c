#include <stdio.h>
#define row 10
#define col 100

void inputstr(int t, char in[row][col]);
void outstr(int t, char out[row][col]);

void inputstr(int t, char in[row][col])
{
	int i=0;
	char c='a';

	while(c!='\0')
	{
		scanf("%c", &c);
		in[t][i]=c;
		printf("%c", in[t][i]);
		i++;
	}

}

void outstr(int t, char out[row][col])
{
	int i=0;
	char c='a';

	while(c!='\0')
	{
		c=out[t][i];
		printf("%c", c);
		i++;
	}
}

int main()
{
	int i;
	char s[row][col];

	for(i=0; i<2; i++)
		inputstr(i,s);

	for(i=0; i<2; i++)
		outstr(i,s);

	return 0;
}
