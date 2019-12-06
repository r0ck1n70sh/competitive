#include <bits/stdc++.h>
#define ll long long unsigned int
const ll M=1000000007;
using namespace std;
ll sqr(ll, ll);
int main() {
	int t;
	ll n;
	scanf("%d", &t);
	while(t) {
		scanf("%llu", &n);
		ll result= sqr(n,n);
		printf("%llu\n", result);
		t--;
	}
	return 0;
}
ll sqr(ll n, ll count) {
	if(count==1)
		return n%M;
	if(count&1)
		return (n+sqr((2*n)%M, count/2))%M;	
	return (sqr((2*n)%M, count/2))%M;
}
