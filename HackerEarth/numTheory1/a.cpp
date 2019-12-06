#include <bits/stdc++.h>
#define ll long long unsigned int
#define mod(a) (ll)(a)%M
ll power(ll, ll);
ll modInv(ll, ll);
void extendedEuclid(ll, ll);
ll M ,x ,y, d;
int main() {
	ll A, B, C, res;
	scanf("%llu%llu%llu%llu",&A,&B,&C,&M);
	res=power(A,B);
	res=res*modInv(C,M);
	printf("%llu\n", res);
	return 0;
}
ll power(ll a, ll p) {
	if(p==0)
		return 1;
	if(p&1)
		return a*power(a*a,(p-1)/2) ;	
	return power(a*a, p/2);
}
ll modInv(ll a, ll mod) {
	extendedEuclid(a, mod);
	return (x%M+M)%M;
}
void extendedEuclid(ll A, ll B) {
	if(B==0) {
		d=A;
		x=1;
		y=0;
	}
	else {
		extendedEuclid(B, A%B);
		int temp=x;
		x=y;
		y=temp-(A/B)*y;
	}
}
