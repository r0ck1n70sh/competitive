#include <bits/stdc++.h>
#define mod (int)(1e9+7)
#define maxl (int)(1e5+7)
#define ll long long
using namespace std;
int arr[maxl];
ll dp[maxl];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", arr+i);
	memset(dp, 0 ,sizeof(dp));
	dp[1]=2; dp[0]=1;
	for(int idx=2; idx<=n; idx++){
		dp[idx]+=dp[idx-1];
		if(arr[idx-1]>arr[idx])
			dp[idx]+=dp[idx-2];
		else
			dp[idx]+=dp[idx-1];
		dp[idx]%=mod;
	}
	//for(int i=0; i<=n; i++)
		//printf("%lld ", dp[i]);
	//printf("\n");
	printf("%lld\n", dp[n]);
	return 0;
}
