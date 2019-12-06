#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int t;
	int s, c;
	int**a; int i, j, k, sum;
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d %d", &s, &c);
		
		a=(int**)malloc((s+1)*sizeof(int*));
		for(i=0; i<s+1; i++)
			a[i]=(int*)malloc((s+c+1)*sizeof(int));
		
		for(i=0; i<s+1; i++)
			for(j=0; j<s+c+1; j++)
				a[i][j]=0;
	
		for(i=0; i<s; i++)			//input
			scanf("%d", &a[0][i]);
		
		k=0; sum=a[0][0];
		while(sum!=a[k][s-k-1]){	//difference
	    	k++; sum=0;
			for(i=0; i<s-k; i++) {
				a[k][i]=a[k-1][i+1]-a[k-1][i];
				sum+=a[k][i];
			}
			sum/=s-k;
		}
			
		for(i=k; i>-1; i--)			//build
			for(j=s-i; j<s+c; j++)
				a[i][j]=a[i][j-1]+a[i+1][j-1];
			
		for(int i=0; i<s; i++) {		//output
			for(int j=0; j<s+c; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}
		
		for(i=s; i<s+c; i++)
			printf("%d ", a[0][i]);
		
		free(a);
		printf("\n");					//End of Test Case
	}
	return 0;
}
