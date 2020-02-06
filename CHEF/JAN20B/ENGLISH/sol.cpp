#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxl=1e5+3;
int nodes, trie[maxl][676], cnt[maxl];
int dfs(int node, int len){
	ll res=0;
	for(int i=0; i<676; i++){
		if(trie[node][i]){
			res+=dfs(trie[node][i], len+1);
			cnt[node]+=cnt[trie[node][i]];
		}
	}
	while(cnt[node]>1){cnt[node]-=2; res+=len*len;}
	return res;
}
int main(){
	int t; scanf("%d", &t); while(t--) {
		memset(trie,0,sizeof(trie)); memset(cnt,0,sizeof(cnt)); nodes=1;
		int n; scanf("%d", &n);
		for(int i=0;i<n;i++){
			string word, rev; cin>>word; rev=word;
			reverse(rev.begin(), rev.end()); vector<int> v(word.length());
			for(int i=0;i<word.length();i++)
				v[i]=(word[i]-'a')*26+(rev[i]-'a');
			int node=0;
			for(int i=0; i<v.size(); i++){
				if(!trie[node][v[i]]) trie[node][v[i]]=nodes++;
				node=trie[node][v[i]];
			}
			++cnt[node];
		}
		printf("%d\n",dfs(0,0));
	}
	return 0;
}
