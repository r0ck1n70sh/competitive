#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define maxl 11
int dp[maxl][maxl];
void build();
int main() {
	int n, k, p=0, x;
	scanf("%d%d", &n, &k);
	build();
	while(n) {
		scanf("%d", &x);
		if(x%2==0)
			++p;
		--n;
	}
	if(p<k) {
		printf("0\n");
		return 0;
	}
	printf("%d\n", dp[p-k][k]);
	return 0;
}
void build() {
	F(i,0,maxl) {
		dp[i][0]=1; dp[0][i]=1;
	}
	F(i,1,maxl)
		F(j,1,maxl)
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
}
