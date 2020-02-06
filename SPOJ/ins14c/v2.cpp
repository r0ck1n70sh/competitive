#include <bits/stdc++.h>
#define maxl 1000+5
using namespace std;

bool vis[maxl];
int main(){
	int T, N, K;
	string S;
	scanf("%d", &T);
	while(T){
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &N, &K);
		cin>>S;
		
		int di_move= floor((N-K)/2.0);
		int sh_move= ceil((N-K)/2.0);
		
		for(int i=0; i<N; i++) {
			if(sh_move && S[i]=='1') {
				vis[i]=1;
				--sh_move;
			}
			if(di_move && S[i]=='0') {
				vis[i]=1;
				--di_move;
			}
		}
			
		int k=0;
		while(sh_move) {
			if(S[k]=='0' && !vis[k]) {
				--sh_move;
				vis[k]=1;
			}
			k++;
		}
		while(di_move) {
			if(S[k]=='1' && !vis[k]) {
				--di_move;
				vis[k]=1;
			}
			k++;
		}
		
		for(int i=0; i<N; i++)
			if(!vis[i])
				cout<<S[i];
		printf("\n");		
		--T;
	}
	return 0;	
}
