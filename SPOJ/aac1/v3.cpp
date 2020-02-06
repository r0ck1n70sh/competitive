//using djikstra's algorithm

#include <bits/stdc++.h>
#define maxl 100000+5
#define ll long long unsigned int
#define PII pair<ll, int>
using namespace std;

array<vector<int>, maxl> graph;
ll dist[maxl];
bool vis[maxl];

int main(){
	int T, M, N;
	scanf("%d", &T);
	while(T){		
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &N, &M);
		for(int i=1; i<N+1; i++)
			dist[i]=maxl;
			
		int x1, x2;
		for(int i=0; i<M; i++){
			scanf("%d%d", &x1, &x2);
			graph[x1].push_back(x2);
			graph[x2].push_back(x1);
		}
		
		priority_queue <PII, vector<PII>, greater<PII>> S;
		S.push({0,1});
		dist[1]=0;

		while(!S.empty()) {
			int parent= S.top().second;
			ll parentDist= S.top().first;
			S.pop();
			
			if(vis[parent])
				continue;
			vis[parent]=1;
			
			for(ll i=0; i<graph[parent].size(); i++) {
				int child= graph[parent][i];
				
				if(parentDist+1<dist[child]) {
					dist[child]=dist[parent]+1;
					S.push({dist[child], child});
				}			
			}			
		}

		printf("%llu\n", dist[N]);
		
		T--;
	}
	return 0;
}
