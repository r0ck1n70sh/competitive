#include <stdio.h>
#include <stdbool.h>

int main()
{
        int a, b, n, A[100];
        int i, am=0, bm=0, cm=0;
        bool p=false, q=false;

        scanf("%d%d%d",&n, &a, &b);
        
        for(i=0; i<n; i++)
        {
                scanf("%d", &A[i]);
        }

        for(i=0; i<n; i++)
        {
                if(A[i]%a==0)
                {
                        am+=1;
                        p=true;
                }
                if(A[i]%b==0)
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
