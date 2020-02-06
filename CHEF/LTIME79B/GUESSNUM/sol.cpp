#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	unordered_set<ll> div; set<ll> res;
	int t; scanf("%d",&t); while(t--){
		ll A,M; scanf("%lld%lld",&A,&M);
		for(ll n=1;n*n<=M;n++){
			if(M%n==0){
				div.insert(n); div.insert(M/n);
			}
		}
		for(auto D:div){
			ll q, rem=M/D; rem--;
			if(rem%A) continue;
			q=rem/A;
			//if(q==0) continue;
 			res.insert(q*D);
		}
		res.erase(0);
		printf("%lu\n",res.size());
		for(auto k:res) printf("%lld ",k);
		printf("\n"); div.clear(); res.clear();
	}
	return 0;
}
