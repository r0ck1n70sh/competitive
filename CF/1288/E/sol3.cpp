#include <bits/stdc++.h>
using namespace std;
const int maxl= 3e5+5;
int f[3*maxl];
void upd(int x, int val){
	for(int i=x;i>=0;i=(i&(i+1))-1) f[i]+=val;
}
int get(int x){
	int res=0; for(int i=x;i<maxl;i|=i+1) res+=f[i];
	return res;
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int>mn(n, 0), mx(n,0);
	for(int i=0;i<n;i++) mn[i]=i;
	vector<int>a(m);
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]); --a[i]; mn[a[i]]=0;
	}
	vector<int> pos(n);
	for(int i=0;i<n;i++) {pos[i]=n-i-1; upd(i,1);}
	for(int i=0;i<m;i++){
		mx[a[i]]= max({mx[a[i]], get(pos[a[i]]+1)});
		upd(pos[a[i]],-1);
		pos[a[i]]=i+n; upd(pos[a[i]],1);
	}
	for(int i=0;i<n;i++) mx[i]= max({mx[i], get(pos[i]+1)});
	for(int i=0;i<n;i++) printf("%d %d\n", mn[i]+1, mx[i]+1);
}
