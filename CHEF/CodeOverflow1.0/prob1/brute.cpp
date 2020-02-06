#include <bits/stdc++.h>
#define mod (int)(1e9+7)
#define maxl (int)(1e5+1)
using namespace std;
vector<int> dp(maxl);
int main(){
	int d1, d2, n;
	scanf("%d%d%d", &n, &d1, &d2);
	dp[1]=d1;
	dp[2]=d2;
	if(n==1)
		printf("%d\n", d1);
	else if(n==2)
		printf("%d\n", d2);
	else{
		for(int i=3; i<=n; i++){
			dp[i]= (3*(dp[i-1]%mod)+4*(dp[i-2]%mod))%mod;
			//d1=d2;
			//d2=res;
		}
		printf("%d\n", dp[n]);
	}
}
