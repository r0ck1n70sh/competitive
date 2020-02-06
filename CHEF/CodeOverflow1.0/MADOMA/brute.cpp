#include <bits/stdc++.h>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;
int main(){
	ll d1, d2, n, res;
	ll a, b;
	scanf("%lld\n%lld%lld", &n, &d1, &d2);
	a=d1; b=d2;
	if(n==1)
		printf("%lld\n", d1);
	else if(n==2)
		printf("%lld\n", d2);
	else{
		for(ll i=3; i<=n; i++){
			res=3*d2+4*d1;
			printf("{%lld, %lld}\n", d2/a, d1/b);
			if(res>mod)
				res%=mod;
			d1=d2;
			d2=res;
		}
		printf("%lld\n", res);
	}
	return 0;
}
