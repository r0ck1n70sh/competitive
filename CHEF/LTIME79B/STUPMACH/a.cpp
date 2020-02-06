#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
multimap<ll,ll> mp;
int main(){
	int t; scanf("%d",&t); while(t--){
		int n; ll ans=0; scanf("%d",&n);
		for(ll i=0,x;i<n;i++) {
			scanf("%lld",&x); mp.insert({x,i});
		}
		//for(auto m:mp) printf("{%d %d} ",m.first,m.second);
		ll curr=n, prv=0;
		for(auto m:mp){
			if(m.second>curr) continue;
			ans+=(m.first-prv)*(curr);
			curr=m.second, prv=m.first; 
		}
		printf("%lld\n",ans); mp.clear();
	}
	return 0;
}
