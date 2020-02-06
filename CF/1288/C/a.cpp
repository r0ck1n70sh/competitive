#include <bits/stdc++.h>
typedef long long ll;
const int maxl=1e3+3, mod=1e9+7;
using namespace std;
ll C(int n, int r){
	if(r==0||n==r) return 1; if(r==1||n-r==1) return n;
	int dp[r+1];
	memset(dp,0,sizeof(dp)); dp[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=min(i,r);j>0;j--)
			dp[j]=(dp[j]+dp[j-1])%mod;
	return dp[r];
}
int main(){
	int n, m; scanf("%d%d",&n,&m);
	printf("%lld\n", C(n+2*m-1, 2*m));
	return 0;
}
