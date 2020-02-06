#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		int n,m;cin>>n>>m;
		vector<int> a(n), b(m);
		unordered_set<int> mp;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int j=0;j<m;j++) {cin>>b[j]; mp.insert(b[j]);};
		int i=0, j=0, time=0;
		for(;i<n&&j<m;i++,j++){
			if(a[i]!=b[j]) break;
			++time; mp.erase(mp.find(b[j]));
		}
		int len=int(mp.size());
		while(!mp.empty()){
			if(mp.find(a[i])!=mp.end())
				mp.erase(mp.find(a[i]));
			i++;
		}
		time+=(len-1)+2*(i-j)-1;
		cout<<time<<"\n";
	}
}
