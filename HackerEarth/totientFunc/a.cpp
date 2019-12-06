#include <bits/stdc++.h>
#define maxl 1000000+1
int phi[maxl];
void buildTot(int);
int main() {
	int n;
	scanf("%d", &n);
	buildTot(n);
	printf("%d\n", phi[n]);
	return 0;
}
void buildTot(int n) {
	for(int i=1; i<n+1; i++)
		phi[i]=i;
	for(int p=2; p<n+1; p++) {
		if(phi[p]==p) {
			phi[p]=p-1;
			for(int i=2*p; i<n+1; i+=p)
				phi[i]=(phi[i]/p)*(p-1);
		}
	}
}
