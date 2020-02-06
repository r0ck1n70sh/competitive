#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll lcm(ll a, ll b){
	return a*b/(__gcd(a,b));
}
int main(){
	ll n; scanf("%lld", &n);
	ll ans;
	for(ll i=1; i*i<=n; i++) if(n%i==0 && lcm(i, n/i)==n) ans=i;
	printf("%lld %lld\n", ans, n/ans);
}
