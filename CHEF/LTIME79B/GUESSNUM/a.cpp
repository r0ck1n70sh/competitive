#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;scanf("%d",&t);while(t--){
		ll m,a; scanf("%lld%lld",&a,&m);
		vector<ll> res;
		for(ll n=m/(a+1)+1;n<=m/a;n++){
			if(m%n==0) continue;
			if(n%(m%n)==0) res.push_back(n); 
		}
		printf("%lld\n",res.size());
		for(ll i=0;i<res.size();i++) printf("%lld ",res[i]);
		printf("\n");
	}
	return 0;
}
