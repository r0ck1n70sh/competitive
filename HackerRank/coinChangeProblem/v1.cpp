#include <bits/stdc++.h>
using namespace std;
int coin[55];
int dp[255];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++)
		scanf("%d", coin+i);
	
	sort(coin, coin+m);
	memset(dp,0,sizeof dp);
	dp[0]=1;
	
	for(int i=0; i<m; i++) {
		for(int k=1; k<=n; k++) {
			if(k<coin[i])
				continue;
			dp[k]+=dp[k-coin[i]];
		}
	}
	printf("%d", dp[n]);
	return 0;
}
