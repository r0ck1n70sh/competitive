#include <bits/stdc++.h>
using namespace std;
typedef double dd;
const int maxn=600, maxk=2000;
dd dp[maxn][maxk];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		for(int k=1;k<=6;k++){
			dp[1][k]=1.0/6.0;
		}
		int N,K; scanf("%d%d",&N,&K);
		if(K<N||6*N<K||N>maxn||K>maxk) {printf("0\n"); continue;}
		//printf("%lf:",dp[N][K-1]);
		for(int n=2;n<=N;n++)
			for(int k=n;k<=6*n;k++)
				for(int p=1;p<=6;p++){
					if(k-p<1) break;
					if(k-p<n-1||k-p>6*(n-1)) continue;
					dp[n][k]+=(dp[n-1][k-p]/6.0);
				}
		//for(int i=1;i<=4;i++){
			//for(int k=i;k<=6*i;k++) 
				//printf("{%d,%d}:%lf ",i,k,dp[i][k]);
			//printf("\n");
		//}
		//printf("%lf:",dp[N][K]);
		printf("%d\n", int(dp[N][K]*100.0));		
	}
	return 0;
}
