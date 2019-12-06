#include <bits/stdc++.h>
#define maxl 10
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define ul unsigned int
unsigned int INF=1000000000+7;
int hPath(int);
int A[10][10]={0};
using namespace std;
int main() {
	int N, M, x, y, z;
	int minStr;
	scanf("%d%d",&N, &M);
	F(m,0,M){
		scanf("%d%d%d",&x,&y,&z);
		A[x-1][y-1]=z; A[y-1][x-1]=z;
	}	
	minStr=hPath(N);
	printf("%d\n",minStr);
	return 0;
}
int hPath(int n) {
	ul minCost=INF;
	ul dp[n][1<<n];
	memset(dp,-1,sizeof(dp));
	F(i,0,n)
		dp[i][1<<i]=0;
	
	F(i,0,(1<<n))
		F(j,0,n)
			if(i&(1<<j)) {
				F(k,0,n)
					if(k!=j&&A[k][j]&&(dp[k][i^(1<<j)]<INF)&&(i&(1<<k))) {
						dp[j][i]=min(dp[j][i],dp[k][i^(1<<j)]+A[j][k]);
					}
			}
	F(i,0,n) {
		if(dp[i][(1<<n)-1]<minCost&&dp[i][(1<<n)-1]>0)
			minCost=dp[i][(1<<n)-1];
	}
	return minCost;
}

