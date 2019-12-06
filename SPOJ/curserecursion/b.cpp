#include <bits/stdc++.h>
#define ll long long unsigned int
ll posNK(ll, ll);
ll pwd(ll);
using namespace std;
int main() {
	int T;
	ll N, K;
	scanf("%d",&T);
	while(T) {
		scanf("%llu%llu",&N, &K);
		if((ll)log2(K+1)>N)
			printf("0\n");
		else
			printf("%llu\n", posNK(N,K));
		T--;
	}
	return 0;
}
ll posNK(ll n, ll k){
	n=min(pwd(k),n);
	while((ll)log2(k)!=n-1) {
		if((ll)log2(k)>n-1)
			k-=(1<<(n-1));
		n=min(n-1, pwd(k));
	}
	return n;
}
ll pwd(ll x) {
	x|=(x>>1);
	x|=(x>>2);
	x|=(x>>4);
	x|=(x>>8);
	x|=(x>>16);
	x|=(x>>32);
	
	return (x+1)>>1;	
}
