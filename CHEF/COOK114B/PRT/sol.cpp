#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7, maxl=3e6+1;
int c[maxl],a[maxl],deg[maxl],l[maxl];
vector<int> v[maxl];
int leaf=0;
void dfs(int node, int par){
	if(deg[node]==1) l[node]=1;
	else l[node]=0;
	int s=0;
	for(int i=0;i<int(v[node].size());i++)
		if(v[node][i]!=par){
			dfs(v[node][i],node);
			l[node]+=l[v[node][i]];
			s+=l[v[node][i]];
		}
	int val=0;
	for(int i=0;i<int(v[node].size());i++)
		if(v[node][i]!=par) val+=(s-l[v[node][i]])*(l[v[node][i]]);
	val/=2;
	val+=l[node]*(leaf-l[node]);
	c[node]=val;
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n,sum=0,res=0; scanf("%d",&n); leaf=0;
		for(int i=0;i<n;i++) {
			scanf("%d",&a[i]); sum+=a[i]; sum%=mod;
			v[i].clear(); deg[i]=0;
		}
		for(int i=0,x,y;i<n-1;i++){
			scanf("%d%d",&x,&y); x--;y--;
			v[x].push_back(y); v[y].push_back(x); deg[x]++; deg[y]++;
		}
		if(n==1) {printf("0\n");continue;}
		if(n==2) {printf("%d\n",sum);continue;} int root;
		for(int i=0;i<n;i++){
			if(deg[i]==1) leaf++;
			else root=i;
		}
		dfs(root,-1); sort(a,a+n); sort(c,c+n);
		for(int i=0;i<n;i++){
			c[i]%=mod; res=(res+(c[i]*a[i])%mod)%mod;
		}
		printf("%d\n",res);
	}
}
