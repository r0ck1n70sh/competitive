#include <bits/stdc++.h>
using namespace std;
const int maxl=1e3+4, INF=1e4;
int dp[maxl][2];
int main(){
	int t; scanf("%d",&t);
	while(t--){
		string s; cin>>s; int n=s.length();
		if(n<=3) {printf("0\n"); continue;}
		if(s[0]=='0') dp[0][0]=1, dp[0][1]=0;
		else dp[0][0]=0, dp[0][1]=1;
		for(int i=1;i<n;i++){
			for(int w=0;w<=1;w++)
				dp[i][w]=dp[i-1][w]+(s[i]=='0'+w);
		}
		int res=n;
		for(int w=0;w<=1;w++)
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n-1;j++)
					res=min(res, dp[i][w]+(dp[n-1][w]-dp[j+1][w])+(j-i-1)-(dp[j][w]-dp[i+1][w]));
		memset(dp,0,sizeof(dp));
		printf("%d\n", res);
	}
}
