#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_const(int**a, int k, int s);
int main() {
	int k, n, t;
	int s, c;
	int**a;
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d %d", &s, &c);
		n=s+c;
		k=0;
		
		a=(int**)malloc((n+1)*sizeof(int*));
		for(int i=0; i<n; i++)
			a[i]=(int*)malloc((n+1)*sizeof(int));
		
		memset(a, 0, (n+1)*(n+1)*sizeof(int));
	
		for(int i=0; i<s; i++)			//input
			scanf("%d", &a[i][0]);
		
		while(check_const(a, k, s)==0){	//difference
	    	k++;
			for(int j=0; j<s-k; j++)
				a[j][k]=a[j+1][k-1] -a[j][k-1];
		}
			
		for(int i=k; i>-1; i--)			//build
			for(int j=s-i; j<n; j++)
				a[j][i]=a[j-1][i]+a[j-1][i+1];
			
/*		for(int i=0; i<n; i++) {		//output
			for(int j=0; j<n; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		} */
		
		for(int i=s; i<n; i++)
			printf("%d ", a[i][0]);
		
		free(a);
		printf("\n");					//End of Test Case
	}
	return 0;
}

int check_const(int**a, int k, int s) {
	int sum=0;
	for(int i=0; i<s-k; i++)
		sum+=a[i][k];
		
	sum/=(s-k);
	if(sum==a[s-k-1][k])
		return 1;
	return 0;
}	
