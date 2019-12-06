#include<stdio.h>
#include<stdlib.h>
void check(int,float*, float*);
int main() {
	int t, n, i;
	float *a, *b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		a=(float *)malloc(sizeof(float)*n);
		b=(float *)malloc(sizeof(float)*n);
		
		for(i=0;i<n;i++)
			scanf("%f", a+i);
		for(i=0;i<n;i++)
			scanf("%f", b+i);
			
		check(n,a,b);
		free(a);
		free(b);
	}
	return 0;
}

void check(int n, float *a, float *b) {
	int i;
	float sum;
	if(a[0]!=0||b[n-1]!=0||a[n-1]!=b[0]) {
		printf("No\n");
		return;
	}
	sum=a[n-1];
	for(i=0; i<n; i++) {
		if(a[i]+b[i]<sum||a[i]+sum<b[i]||b[i]+sum<a[i]) {
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
}
