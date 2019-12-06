#include <stdio.h>
#define row 10
#define col 100

void inputstr(char in[col]);
void outstr(char out[col]);

void inputstr(char in[col])
{
        int i=0;
        char c='a';

        while(c!='\0')
        {
                scanf("%c", &c);
                in[i]=c;
                //printf("%c", in[i]);
                i++;
        }

}

void outstr(char out[col])
{
        int i=0;
        char c='a';

        while(c!='\0')
        {
                c=out[i];
                printf("%c", c);
                i++;
        }
}

int main()
{
        int i;
        char s[col];
 
        for(i=0; i<2; i++)
                inputstr(s);

        for(i=0; i<2; i++)
                outstr(s);

        return 0;
}

