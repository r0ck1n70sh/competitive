//greedy approach

#include <bits/stdc++.h>
#define maxl (ll)(1e5+5)
#define ll long long unsigned int
#define PII pair<int ,int>
#define PIL pair<int ,ll>
using namespace std;

array<vector<int>, maxl> G;
ll V[maxl];
ll tree[maxl];
ll E[maxl];
bool vis[maxl];

int main(){
	int T, N;
	scanf("%d", &T);
	while(T){
		int coin=0;
		int v1, v2;
		scanf("%d", &N);
		
		for(int i=2; i<N+1; i++) {
			scanf("%d%d%lld", &v1, &v2, E+i);
			G[v1].push_back(v2);
			G[v2].push_back(v1);
		}
	
		for(int i=1; i<N+1; i++) {
			scanf("%lld", V+i);
		}
	
		sort(V+1, V+N+1, greater<ll>());
		sort(E+2, E+N+1, greater<ll>());
		memset(vis, 0, sizeof(vis));
		
		queue<int> Q;
		Q.push(1);
		int k=1;
		if(V[1]<E[2])
			coin++;
		tree[1]= max(V[1], E[2]);
		
		while(!Q.empty()) {
			int curr= Q.front();
			Q.pop();

			if(vis[curr])
				continue;
			vis[curr]=1;
					
			for(int child=0; child<G[curr].size(); child++) {
				Q.push(G[curr][child]);
				if(V[k+child]<E[k+child] && !vis[k+child])
					coin++;
				tree[G[curr][child]]=max(E[k+child], V[k+child]);		
			}
			k++;
		}
				
		printf("%d\n", coin);		
		--T;
	}
	
	return 0;
}
