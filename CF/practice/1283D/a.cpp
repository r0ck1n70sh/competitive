#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+1;
unordered_set<int> pts;
int main(){
	int n,m; cin>>n>>m;
	vector<int> x(n);
	for(int i=0;i<n;i++) {cin>>x[i];pts.insert(x[i]);}
	//for(auto k:pts) cout<<k<<" ";
	//cout<<"\n";
	sort(x.begin(),x.end());
	int cnt=m, f=1; long long res=0;
	for(int dist=1;dist<=m&&f;dist++)
		for(int i=0;i<n;i++){
			if(pts.find(x[i]-dist)==pts.end()) {
				pts.insert(x[i]-dist);
				res+=min(dist, i>0?abs(x[i-1]-x[i]+dist):inf);
				cnt--;
			}
			if(cnt==0) {f=0; break;}
			if(pts.find(x[i]+dist)==pts.end()) {
				pts.insert(x[i]+dist);
				res+=min(dist, i<n-1?abs(x[i+1]-x[i]-dist):inf);
				cnt--;
			}
			if(cnt==0) {f=0; break;}
		}
	cout<<res<<"\n";
	for(int i=0;i<n;i++) pts.erase(pts.find(x[i])); 
	for(auto k:pts) cout<<k<<" ";
	cout<<"\n";
}
