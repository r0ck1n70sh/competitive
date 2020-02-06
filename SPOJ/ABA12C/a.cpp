#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+10;
int c[101], dp[101][101];
int main(){
	int t;scanf("%d",&t);while(t--){
		int N,K; scanf("%d%d",&N,&K);
		for(int i=1;i<=K;i++) scanf("%d",&c[i]);
		for(int n=1;n<=N;n++)
			for(int w=1;w<=K;w++)
				dp[w][n]=inf;				
		for(int i=1;i<=K;i++) if(c[i]!=-1) dp[i][1]=c[i];
		for(int n=1;n<=N;n++)
			for(int w=1;w<=K;w++)
				for(int k=1;k<=K;k++){
					if(c[k]==-1) continue;
					dp[w+k][n+1]=min(dp[w+k][n+1], dp[w][n]+c[k]);
				}
		int ans=inf;
		for(int n=1;n<=N;n++)
			ans=min(ans,dp[K][n]);
		printf("%d\n",(ans<inf)?(ans):(-1));
	}
	return 0;
}
