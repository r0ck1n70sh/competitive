#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
const int maxl= (int)(1e6+7);
const int mod= (int)(1e9+7);
ll modpow(ll a, int n){
	if(n<0)	return 0;if(n==0) return 1;if(n==1) return a;
	if(n&1) return (modpow(a,n-1)*a)%mod;
	ll res=modpow(a,n/2)%mod; return (res*res)%mod;	
}
ll modinv(int n){
	return modpow(n, mod-2);
}
ll factdp[maxl];
ll fact(int n){
	if(factdp[n]!=0) return factdp[n];
	return factdp[n]=(n*fact(n-1))%mod;
}
unordered_map<int,int> m;
int main(){
	int t;
	scanf("%d", &t);
	memset(factdp, 0, sizeof(factdp)); factdp[0]=1;
	while(t--){
		int n; scanf("%d", &n);
		for(int i=1 ,x; i<=2*n; i++) {
			scanf("%d", &x); if(m.count(x))m[x]+=1; else m.insert({x,1});
		}
		if(n==1&&m.size()==1) {printf("1\n"); m.clear();continue;}
		ll res=0; 
		for(auto it=m.begin(); it!=m.end(); it++){
			if((it->S)&1) continue;
			int sum=it->F, flag=0;
			vector<int> s; ll ans;
			for(auto jt=m.begin(); jt!=m.end(); jt++){
				int k=jt->F; if(it->F==k) continue;
				if(m[sum-k]==m[k]){
					if(sum-k<k) continue;
					if(sum-k==k) s.push_back(m[k]/2);else s.push_back(m[k]);
				}
				else {flag=1; break;}
			}
			if(flag) continue;
			if(sum%2==0&&m.count(sum/2)) ans=modpow(2,n-2);
			else ans=modpow(2,n-1); ans=(ans*fact(n-1))%mod;
			for(int i=0; i<s.size(); i++) ans=(ans*modinv(fact(s[i])))%mod;
			res= (res+ans)%mod;
		}
		printf("%lld\n", res); m.clear();
	}
	return 0;
}
