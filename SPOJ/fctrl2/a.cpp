#include <bits/stdc++.h>
#define ll long long unsigned int
void build(int);
ll f[101];
int main() {
	int t, n;
	memset(f, 0, sizeof f);
	f[1]=1;
	scanf("%d", &t);
	while(t) {
		scanf("%d",&n);
		if(f[n]<1)
			build(n);
		printf("%llu\n", f[n]);
		--t;
	}
	return 0;
}
void build(int n) {
	int i;
	for(i=1; i<n; i++)
		if(f[i]<1)
		 break;
	//printf("%d\n",i);
	for(int k=i; k<n+1; k++)
		f[k]=k*f[k-1];
}
