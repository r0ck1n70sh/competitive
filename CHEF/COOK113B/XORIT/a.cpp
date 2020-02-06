#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ef(ll n){
	ll res=0;
	for(int i=1;i<32;i++)
		res+=(ll)(n/(1<<i));
	return res;
}
ll p2s(ll l, ll r){
	ll res=0;
	for(int i=1;i<32;i++){
		ll p=(1<<i);
		if(p<l||p>r) continue;
		res+=2*i-p-1;
	}
	return res;
}
int main(){
	int t; scanf("%d",&t); while(t--){
		ll l,r; scanf("%lld%lld",&l,&r);
		ll res=(r*(r+1))/2-(l*(l-1))/2;//printf("%lld\n", res);
		ll odd=(r-l+1)/2+((l&1)&&(r&1));//printf("%lld\n", res);
		res-=odd;//printf("%lld\n", res);
		res-=2*(ef(r)-ef(l-1));//printf("%lld\n", res);
		res+=p2s(l,r);//printf("%lld\n", res);
		printf("%lld\n", res);
	}
	return 0;

}
//int main(){
	//printf("%lld\n",p2s(1,10));
	//printf("%lld\n", 2*(ef(10)-ef(0)));
//}
