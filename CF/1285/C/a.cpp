#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/(gcd(a,b));
}
int main(){
	ll x; cin>>x; vector<ll> fact;
	for(int i=1; i*i<=x; i++)
		if(x%i==0){fact.push_back(i); fact.push_back(x/i);}
	ll res=(1e12+5), res2;
	for(int i=0; i<fact.size(); i++){
		for(int j=i+1; j<fact.size(); j++){
			if(lcm(fact[i], fact[j])==x && res>max(fact[i],fact[j]))
				{res=max(fact[i], fact[j]); res2=min(fact[i], fact[j]);}
		}
	}
	printf("%lld %lld\n", res2, res);
}
