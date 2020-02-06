#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ll;
const ll mod=1e9+7;
int main(){
	int t; scanf("%d",&t); while(t--){
	ll l, r; scanf("%llu%llu",&l,&r);
	ll res=0;
	for(int j=0;j<=60;j++){
		if((l&(1LL<<j))==0) continue;
		ll k=(1LL<<j)-(l&((1LL<<j)-1));
		ll c=(ll)min(k,r-l+1)%mod;
		res=(res+(((1LL<<j)%mod)*c)%mod)%mod;
	}
	printf("%llu\n", res);	
	}
}
