#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxl 1000000
int N[maxl][maxl];
int *R, *C;
int count(int);
int psb(int, int, int);
int main() {
	int t, n, k, r, c, i, p;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &k);
		memset(N, 0, sizeof(int)*maxl*maxl);
		for(i=0;i<k;i++) {
			scanf("%d %d", &r, &c);
			N[r][c]=1;
		}
		R=(int*)malloc(sizeof(int)*n);
		C=(int*)malloc(sizeof(int)*n);
		memset(R,0,sizeof(int)*n);
		memset(C,0,sizeof(int)*n);
		p=count(n);
		printf("%d ",p);
		for(i=0;i<p;i++)
			printf("%d %d ",R[i], C[i]);
		printf("\n");
		free(R);
		free(C);
	}
	return 0;
}

int count(int n) {
	int k=0, p=0, i, j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(psb(n,i,j)) {
				R[k]=i;
				C[k]=j;
				N[i][j]=1;
				p++; k++;
				break;
			}
		}
	}
	return p;	
}

int psb(int n, int r, int c) {
	int i;
	for(i=0;i<n;i++)
		if(N[i][c])
			return 0;
	for(i=0;i<n;i++)
		if(N[r][i])
			return 0;
	return 1;			
}
