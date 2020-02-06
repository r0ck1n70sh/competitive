#include <bits/stdc++.h>
#define x first
#define y second
#define pt pair<int, int>
using namespace std;
map<int, int> ls; const int INF=2e9;
int get(vector<pt>a){
	int cnt=0, l= -INF, r= -INF;
	sort(a.begin(), a.end());
	for(int i=0;i<a.size();i++){
		if(a[i].x>r){
			if(r!=-INF) ls[l]=0;
			++cnt; l=a[i].x; r=a[i].y;
		}
		else r=max(r, a[i].y);		
	}
	ls[l]=0; return cnt;
}
void process(vector<pair<int, pt>>&qr, vector<int>&ans){
	set<int>open;
	for(int i=0;i<qr.size();i++){
		vector<int> op, cl; int j=i-1;
		while(j+1<int(qr.size())&&qr[j+1].x==qr[i].x){ ++j;
			if(qr[j].y.x==1) op.push_back(qr[j].y.y);
			else cl.push_back(qr[j].y.y);
		}
		if(open.size()==1&&!op.empty()) ++ans[*open.begin()];
		for(auto it:op) open.insert(it);
		for(auto it:cl) open.erase(it);
		i=j;
	}	
}
void solve(){
	int n; scanf("%d", &n);
	vector<pt>a(n);
	for(int i=0;i<n;i++) scanf("%d%d", &a[i].x, &a[i].y);
	vector<pair<int,pt>> qr;
	for(int i=0;i<n;i++) {
		qr.push_back({a[i].x,{1,i}}); qr.push_back({a[i].y,{-1,i}}); }
	sort(qr.begin(), qr.end());	vector<int> ans(n,0); ls.clear();
	int cur= get(a); process(qr, ans);
	for(int i=0; i<n; i++) if(ls.count(a[i].x)) ++ls[a[i].x];
	for(int i=0; i<n; i++) if(ls[a[i].x]==1) --ans[i];
	printf("%d\n", *max_element(ans.begin(), ans.end())+ cur);	
}
int main(){
	int t; scanf("%d",&t);
	while(t--) solve();
	return 0;
}
