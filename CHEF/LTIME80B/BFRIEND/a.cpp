#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;cin>>t;while(t--){
		int n,a,b,c; cin>>n>>a>>b>>c;
		vector<int>f(n);
		for(int i=0;i<n;i++) cin>>f[i];
		ll ans=1e10;
		for(int i=0;i<n;i++) ans=min(ans, ll(abs(f[i]-a)+abs(f[i]-b)));
		
		printf("%lld\n", ans+c);
	}
}
