#include <bits/stdc++.h>
#define ll long long int
int main(){
	ll N, K, g;
	scanf("%lld%lld", &N, &K);
	g=((ll)sqrt(9+8*(N+K)))-6;
	g+=4; g/=2;
	printf("%lld\n",N-g);
	return 0;
}
