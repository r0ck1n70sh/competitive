#include <bits/stdc++.h>
#define mod (ll)(1e9+7)
#define ll long long unsigned
using namespace std;
int main(){
	ll d1, d2, n, res;
	scanf("%llu\n%llu%llu", &n, &d1, &d2);
	if(n==1)
		printf("%llu\n", d1);
	else if(n==2)
		printf("%llu\n", d2);
	else{
		for(size_t i=3; i<=n; i++){
			res=3*d2+4*d1;
			res%=mod;
			d1=d2;
			d2=res;
		}
		printf("%llu\n", res);
	}
}
