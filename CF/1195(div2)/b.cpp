#include <bits/stdc++.h>
#define ll long long
ll mod=1000000000+7;
int main() {
	ll N, K, e;
	ll dp0;
	scanf("%llu%llu", &N, &K);
	N%=mod; K%=mod;
	dp0=(((N+1)*N)%mod)/2;
	printf("%llu\n", dp0);
	for(e=0; e<N; e++) {
		if(dp0==(K%mod)) {
			printf("%llu\n", e);
			break;
		}
		dp0-=(N-e+2);
		if(dp0<0)
			break;
	}
	printf("last:%llu\n",e);
	return 0;
}
