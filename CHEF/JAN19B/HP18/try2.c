//scaling up
#include <stdio.h>
#include <stdbool.h>
//#define max1 100000
unsigned long long max1 = 200000; 

void win(int n,int a, int b, unsigned long A[10][max1], int k)
{
        int i;
        unsigned long am=0, bm=0, cm=0;
        bool p=false, q=false;

        for(i=0; i<n; i++)
        {
                if(A[k][i]%a==0)
                {
                        am+=1;
                        p=true;
                }
                if(A[k][i]%b==0)
                {
                        bm+=1;
                        q=true;
                }
                if(p && q)
                        cm+=1;
                p=false; q=false;
        }

        if(am>bm)
                printf("BOB\n");

        else if(bm==am)
        {
                if(cm%2==0)
                        printf("ALICE\n"); //player#2
                else
                        printf("BOB\n"); //player#1           
        }        
      

        else //bm>am
                printf("ALICE\n");
}

int main()
{
        int t;
        int a[10], b[10];
        unsigned long A[10][max1], n[10];
        int i, j;

        scanf("%d", &t);
        for(i=0; i<t; i++)
        {
                scanf("%d%d%d", &n[i], &a[i], &b[i]);
                for(j=0; j<n[i]; j++)
                {
                        scanf("%lu", &A[i][j]);
                }
        }

        for(i=0; i<t; i++)
                win(n[i], a[i], b[i], A, i);

        return 0;
}
