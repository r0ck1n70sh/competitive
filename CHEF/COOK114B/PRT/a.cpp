#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxl=3e5+5, mod=1e9+7;
int n;
ll a[maxl],c[maxl],vis[maxl];
vector<int> v[maxl];
ll dfs(int node){
	vis[node]=1;
	ll s=0, ss=0; vector<int> h;
	for(int i=0;i<int(v[node].size());i++)
		if(!vis[v[node][i]]) h.push_back(dfs(v[node][i])+1);
	for(int i=0;i<int(h.size());i++) {
		s=(s+h[i])%mod; ss=(ss+(h[i]*h[i])%mod)%mod;
	}
	//c[node]=((s*(n-1))%mod+n-ss-1)%mod;
	c[node]=s;
	return s;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%lld",&a[i]);
		for(int i=0,x,y;i<n-1;i++){
			scanf("%d%d",&x,&y);
			v[x-1].push_back(y-1);v[y-1].push_back(x-1);
		}
		for(int i=0;i<n;i++) printf("%lld ",c[i]); printf("\n");
		memset(vis,0,sizeof(vis));dfs(0);ll sum=0;
		sort(c,c+n); sort(a,a+n);
		for(int i=0;i<n;i++) sum=(sum+(c[i]*a[i])%mod)%mod;
		printf("%lld\n",sum);
		for(int i=0;i<=n;i++) v[i].clear();
	}
	return 0;
}
