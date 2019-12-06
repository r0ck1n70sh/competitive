#include <bits/stdc++.h>
#define ull long long unsigned int
#define maxl 100000+1
#define modulo(n) n%M
const unsigned int M=1000000007;
ull fact(int);
ull memo[maxl];
int main() {
	int n, t;
	ull ans;
	memset(memo, 0, sizeof(memo));
	memo[1]=1;
	memo[0]=1;
	scanf("%d", &t);
	while(t) {
		scanf("%d", &n);
		ans=fact(n);
		//ans%=mod;
		printf("%llu\n", ans);
		t--;
	}
	return 0;
}
ull fact(int n) {
	if(memo[n]!=0)
		return memo[n];
	
//	memo[n]=((n%mod)*(fact(n-1)%mod))%mod;
	memo[n]= modulo(n*fact(n-1));
	return memo[n];	
}
