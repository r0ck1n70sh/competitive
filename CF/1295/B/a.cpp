#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		string s,t; cin>>s>>t;
		int n=int(s.length()), m=int(t.length()), fl=0;
		unordered_set<char> mp;
		for(int i=0;i<n;i++) mp.insert(s[i]);
		for(int i=0;i<m;i++) {
			if(mp.find(t[i])==mp.end()) {fl=1; break;}
		}
		if(fl) {cout<<"-1\n";continue;}
		vector<vector<int>> mpt(m+1,vector<int>(26,0));
		for(int i=1;i<=m;i++){
			++mpt[i-1][t[i]-'a']; mpt[i]=mpt[i-1];
		}
		vector<int>freq(26,0);
		for(int i=0;i<n;i++) ++freq[s[i]-'a'];
		int st=0,ed=m,res=0;
		while(st<m){
			vector<int>cnt(26);
			for(int i=0;i<26;i++)
				cnt[i]=mpt[ed][i]-mpt[st][i];
			int f=1;
			for(int i=0;i<26;i++)
				if(cnt[i]>freq[i]) {f=0;break;}
			if(f) {
				cout<<st<<":"; st=ed;ed=m+1;res++;
			}
			ed--;
		}
		cout<<res<<"\n";
	}
}
