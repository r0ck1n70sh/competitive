#include <bits/stdc++.h>
#define ll long long int
#define mod(a) (int)(a)%m
using namespace std;
ll poe(ll,ll);
ll invMod(ll,ll);
void extendedEuclid(ll, ll);
ll m;
ll x,y,d;
int main() {
	ll a, b, c;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &m);
	ll res1=poe(a, b);
	ll res2=invMod(c,m);
	ll res=((res1%m)*(res2%m))%m;
	printf("%lld\n", res);
	return 0;
}
ll poe(ll a, ll p) {
	ll res=1;
	while(p>0) {
		if(p&1)
			res=(res*a)%m;
		a=(a*a)%m;
		p/=2;		
	}
	return res;	
}
ll invMod(ll c, ll m) {
	extendedEuclid(c, m);
	return (x%m+m)%m;
}
void extendedEuclid(ll a, ll b) {
	if(b==0) {
		d=a; x=1; y=0;
	}
	else {
		extendedEuclid(b, a%b);
		ll temp=x;
		x=y;
		y=temp-y*(a/b);
	}
}
