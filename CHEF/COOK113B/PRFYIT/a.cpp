#include <bits/stdc++.h>
using namespace std;
const int maxl= 1e3+3, INF=1e4+10;
typedef unsigned ul;
ul dp[maxl][2][8];
int main(){
	int t; scanf("%d",&t);
	while(t--){
		string s; cin>>s; int n=int(s.length()); 
		if(n<=3){printf("0\n"); continue;}
		for(int i=0;i<=n;i++)
			for(int msk=0; msk<8; msk++) 
				dp[i][0][msk]=dp[i][1][msk]=INF;
		int ms=4*(s[2]-'0')+2*(s[1]-'0')+(s[0]-'0');
		dp[2][1][ms]=0;
		for(int i=3;i<n;i++){
			for(int msk=0;msk<8;msk++)
				dp[i][0][msk]=1+(min({dp[i-1][0][msk], dp[i-1][1][msk]}));
			for(int msk=(s[i]-'0');msk<8;msk+=2){
				if(s[i]-'0'==0&&msk==2){
					dp[i][1][2]=min({dp[i-1][0][1],dp[i-1][1][1]});
					continue;
				}
				if(s[i]-'1'==0&&msk==5){
					dp[i][1][5]=min({dp[i-1][0][6],dp[i-1][1][6]});
					continue;
				}
				dp[i][1][msk]=min({dp[i-1][0][msk/2],dp[i-1][1][msk/2],dp[i-1][0][4+msk/2],dp[i-1][1][4+msk/2]});
			}
		}
		//for(int i=3;i<n;i++){
			//printf("{%d}: ",i);
			//for(int msk=0;msk<8;msk++)
				//printf("[%d: {%u %u}] ",msk,dp[i][0][msk],dp[i][1][msk]);
			//printf("\n");
		//}
		ul ans=INF;
		for(int msk=0;msk<8;msk++)
			ans=min({ans,dp[n-1][0][msk]});
		for(int msk=(s[n-1]-'0');msk<8;msk+=2)
			ans=min({ans, dp[n-1][1][msk]});
		printf("%u\n", ans);
	}
	return 0;
}
