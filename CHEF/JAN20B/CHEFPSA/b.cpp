#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxl=(1e5+3), mod=1e9+7; 
int arr[2*maxl], dp[maxl];
ll fact(ll); ll modpow(ll, ll); ll modinv(ll);  
int main(){
	int t; scanf("%d",&t); memset(dp, 0, sizeof(dp));
	while(t--){
		int n; scanf("%d", &n); arr[0]=0; arr[1]=0;
		if(n==1){
			int x,y; scanf("%d%d", &x,&y);
			if(x==y) printf("1\n"); else printf("0\n");
			continue;
		}
		for(int i=2; i<=2*n+1; i++) scanf("%d", arr+i);
		sort(arr, arr+2*n+2); ll sum=arr[2*n+1]+arr[0]; int f=0, pe=0;
		//for(int i=0; i<=2*n+1; i++) printf("%d ", arr[i]); printf("\n");
		unordered_map<int, int> m;
		for(int i=1;i<=n;i++) { 
			if(arr[i]+arr[2*n+1-i]!=sum) {f=1;break;}
			if(arr[i]==arr[2*n+1-i]) pe++;
			if(i>1) m[arr[i]]++;
		}
		if(f) {printf("0\n"); continue;}
		ll ans=modpow(2,n-1-pe); ans=(ans*fact(n-1))%mod;
		for(auto i:m) ans=(ans*(modinv(fact(i.second))))%mod;
		printf("%lld\n", ans);
	}
}
ll fact(ll n){
	if(n==0) return 1;
	if(dp[n]!=0) return dp[n];
	return dp[n]=n*fact(n-1);
}
ll modpow(ll a, ll n){
	if(n<0) return 0; if(n==0) return 1;
	if(n&1) return (a*modpow(a, n-1))%mod;
	int res=modpow(a, n/2); return(res*res)%mod;
}
ll modinv(ll a){
	return modpow(a, mod-2);
}
