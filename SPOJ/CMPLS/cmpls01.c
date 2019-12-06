#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[10][100];
int check_const(int k, int s);
int main() {
	int k=0, n;
	int s, c;
	scanf("%d %d", &s, &c);
	n=s+c;
	memset(a, 0, 1000*sizeof(int));
	
	for(int i=0; i<s; i++)
		scanf("%d", &a[0][i]);
		
	while(check_const(k, s)!=1){
		k++;
		for(int j=0; j<s-k; j++)
			a[k][j]=a[k-1][j+1] -a[k-1][j];
	}
			
	for(int i=k; i>-1; i--)
		for(int j=s-i; j<n; j++)
			a[i][j]=a[i][j-1]+a[i+1][j-1];
			
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
		
	return 0;
}

int check_const(int k, int s) {
	int sum=0;
	for(int i=0; i<s-k; i++)
		sum+=a[k][i];
		
	sum/=(s-k);
	if(sum==a[k][s-k-1])
		return 1;
	return 0;
}	
