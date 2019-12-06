#include<stdio.h>
#include<stdlib.h>

struct pt {
	int x;
	int y;
};
int psb(int,int, struct pt*,int);
int rks(int, int*, struct pt*, struct pt*);
int main() {
	int t, n, k, i, p;
	struct pt *a;
	struct pt *A;
	scanf("%d\n", &t);
	while(t--) {
		scanf("%d %d\n", &n, &k);
		A=(struct pt*)malloc(sizeof(struct pt)*n);
		a=(struct pt*)malloc(sizeof(struct pt)*(n-k));
		for(i=0;i<k;i++)
			scanf("%d %d\n", &A[i].x, &A[i].y);
		p=rks(n, &k, a, A);
		printf("%d ",p);
		for(i=0;i<p;i++)
			printf("%d %d ", a[i].x, a[i].y);
		printf("\n");
		free(A); free(a);
	}
	return 0;
}

int rks(int n, int *k, struct pt *a, struct pt *A) {
	int p=0, m=0, i, j;	
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(psb(i,j,A,*k)) {
				a[m].x=i; a[m].y=j;
				(*k)++; p++; m++;
				A[*k-1].x=i; A[*k-1].y=j;
				break;
			}
		}
	}
	return p;
}

int psb(int r, int c, struct pt *A, int k) {
	int i;
	for(i=0;i<k;i++)
		if(A[i].x==r||A[i].y==c)
			return 0;
	
	return 1;
}
