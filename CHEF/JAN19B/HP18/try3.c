//without function win
#include <stdio.h>
#include <stdbool.h>
//#define max1 100000
unsigned long long max1 = 200000; 

int main()
{
        int t;
        int a[10], b[10];
        unsigned long long A[10][max1], n[10];
        int i, j;
        unsigned long long am=0, bm=0, cm=0;
        bool p=false, q=false;

        scanf("%d", &t);
        for(i=0; i<t; i++)
        {
                scanf("%d%d%d", &n[i], &a[i], &b[i]);
                for(j=0; j<n[i]; j++)
                {
                        scanf("%llu", &A[i][j]);
                }
        }

        for(i=0; i<t; i++)
        {
              am=0; bm=0; cm=0;
              for(j=0; j<n[i]; j++)
                {
                        if(A[i][j]%a[i]==0)
                        {
                                am+=1;
                                p=true;
                        }
                        if(A[i][j]%b[i]==0)
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

        return 0;
}
