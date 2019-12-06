#include <bits/stdc++.h>
#define ll long long unsigned int
using namespace std;
const ll maxl=1e9;
bool check(ll, ll);
ll sqrll(ll);
int main() {
	ll N, K;
	int t;
	scanf("%d", &t);
	while(t) {
		scanf("%llu%llu", &N, &K);
		if(check(N,K))
			printf("YES\n");
		else
			printf("NO\n");
		--t;
	}
	return 0;
}
bool check(ll N, ll K) {
	if(K>maxl)
		return 1;
	ll b=K*K;
	if(N%b==0)
		return 0;
	return 1;
}
ll sqrll(ll n) {
	if(n==0)
		return 0;
	else
		return (sqrll(n-1)+2*n-1);
}
