#include <bits/stdc++.h>
using namespace std;
const int maxl=1e6+2, alf=26+2;
int nodes, trie[maxl][alf];
int cnt[maxl];
int main(){
	memset(trie, 0, sizeof(trie)); memset(cnt, 0, sizeof(cnt));
	int n, q; scanf("%d%d", &n, &q); nodes=1;
	for(int i=0; i<n; i++){
		int node=0;
		string word; cin>>word;
		for(int idx=0;idx<word.length();idx++){
			if(!trie[node][word[idx]-'a'])
				trie[node][word[idx]-'a']=nodes++;
			node=trie[node][word[idx]-'a']; 
		}
		++cnt[node];
	}
	for(int i=0; i<q; i++){
		string word; int f=0, node=0; cin>>word; 
		for(int idx=0;idx<word.length();idx++){
			if(!trie[node][word[idx]-'a']) {f=1; break;}
			node=trie[node][word[idx]-'a'];
		}
		if(!cnt[node]) f=1;
		if(f) printf("Not Found!\n");
		else printf("Found\n");
	}
	//for(int i=0;i<10;i++)
		//{for(int j=0;j<26;j++) printf("%d ",trie[i][j]); printf("\n");}
}
