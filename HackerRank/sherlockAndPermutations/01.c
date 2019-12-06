#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long unsigned int
#define maxl 1000
ll memo[maxl];
const ll M=1e9+7;
ll fact(ll);
int main() {
	int t, n, m;
	ll ans;
	memset(memo,0,sizeof memo);
	memo[0]=1;
	scanf("%d", &t);
	while(t) {
		scanf("%d%d", &n, &m);
		ans=fact(m+n-1);
		ans/=fact(n);
		ans/=fact(m-1);
		printf("%llu\n",ans);
		--t;
	}
	return 0;
}
ll fact(ll n) {	
	if(memo[n]!=0)
		return memo[n];		
	return memo[n]=(n*fact(n-1))%M;
}
