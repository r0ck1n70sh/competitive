#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int maxl=3e5+5;
typedef pair<int,int> pt;
int n;
int a[maxl];
vector<int> pos[maxl];
pt ans[maxl];

vector<int> t[4*maxl]; int prv[maxl];
void build(int v,int l,int r){
	if(l==r-1) {t[v].push_back(prv[l]); return;}
	int m=(l+r)/2;
	build(v*2,l,m); build(v*2+1,m+1,r);
	t[v].resize(r-1);
	merge(t[v*2].begin(),t[v*2].end(),t[v*2+1].begin(),t[v*2+1].end(), t[v].begin());
}
int get(int v,int l,int r,int L,int R,int val){
	if(L>=R) return 0;
	if(l==L&&r==R) return lower_bound(t[v].begin(),t[v].end(),val)-t[v].begin();
	int m=(l+r)/2;
	return get(v*2,l,m,L,min(m,R),val)+get(v*2+1,m+1,r,max(m,L),R,val);
}
int f[maxl];
void upd(int x){
	for(int i=x;i>=0;i=(i&(i+1))-1) ++f[i];
}
int get(int x){
	int res=0; for(int i=x;i<maxl;i|=i+1) res+=f[i]; return res;
}
int main(){
	int m; scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		scanf("%d", &a[i]); --a[i];
	}
	for(int i=0;i<m;i++) pos[a[i]].push_back(i);
	vector<pt> qr;
	for(int i=0;i<n;i++){
		for(int j=1;j<int(pos[i].size());j++)
			qr.push_back({pos[i][j-1]+1, pos[i][j]-1});
		if(!pos[i].empty())
			qr.push_back({pos[i].back()+1, m-1});
	}
	for(int i=0;i<n;i++) ans[i]={i,i};
	for(int i=0;i<m;i++) ans[a[i]].x=0;
	for(int i=0;i<n;i++){
		int cur=-1; for(auto it:pos[i]) prv[it]=cur, cur=it;
	}
	build(1,0,m);
	for(int i=0;i<qr.size();i++){
		int l=qr[i].x, r=qr[i].y;
		if(r<l) continue;
		int x=a[qr[i].x-1];
		int cnt=get(1,0,m,l,r+1,l);
		ans[x].y= max(ans[x].y, cnt);
	}
	for(int i=0;i<m;i++){
		if(i==pos[a[i]][0])
			ans[a[i]].y= max(ans[a[i]].y, a[i]+get(a[i])); upd(a[i]);
	}
	for(int i=0;i<n;i++){
		if(pos[i].empty()) ans[i].y= max(ans[i].y, i+get(i));
	}
	for(int i=0;i<n;i++) printf("%d %d\n", ans[i].x+1, ans[i].y+1);
	return 0;
}
