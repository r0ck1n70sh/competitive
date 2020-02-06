#include <bits/stdc++.h>
#define maxl 1000+5
using namespace std;

int main(){
	int T, N, K;
	string S;
	bool vis[maxl];
	scanf("%d", &T);
	while(T){
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &N, &K);
		cin>>S;
		
		if(N==K){
			printf("\n");
			--T;
			continue;
		}
		
		int f=0, f1=0, b=N-1;
		int z=0;
		for(int i=1; i<N-K+1; i++) {
			if(i%2==1) {		//minimize
				while(S[f]!='1' && !vis[f] && f<N)
					f++;
				if(f<N) {
					vis[f]=1;
					f++;
				}
				else
					++z;
				continue;
			}					//maximize
			while(S[f1]!='0' && f1<f && f1<N)
				f1++;
			if(S[f1]=='0' && !vis[f1] && f1<N) {
				vis[f1]=1;
				f1++;
			}
			else {
				while(vis[b] && b>-1)
					b--;
				if(b>-1) {
 					vis[b]=1;
					b--;
				}
				else
					++z;
			}			
		}
		
		for(int i=0; i<N-z; i++)
			if(!vis[i])
				printf("%c", S[i]);
		printf("\n");		
		--T;
	}
	return 0;
}
