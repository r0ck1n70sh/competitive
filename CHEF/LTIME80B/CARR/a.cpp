#include <bits/stdc++.h>
using namespace std;
const int maxl=1e5+3, mod=1e9+7;
typedef long long ll;
ll dp[maxl][2];
int main(){
	int t; cin>>t; while(t--){
		int n,m; cin>>n>>m; memset(dp,0,sizeof(dp));
		dp[2][0]=((m%mod)*((m-1)%mod)/2)%mod; dp[2][1]=m%mod;
		for(int i=3;i<=n;i++){
			dp[i][0]=((dp[i-1][0]+dp[i-1][1])*(m-1))%mod;
			dp[i][1]=dp[i-1][0];
		}
		printf("%lld\n", (dp[n][0]+dp[n][1])%mod);
	}
	return 0;
}
