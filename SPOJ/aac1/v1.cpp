#include <bits/stdc++.h>
#define maxl 100000+5
#define ll long unsigned int
using namespace std;

array<vector<int>, maxl> graph;
ll dist[maxl];
bool vis[maxl];

int main(){
	int T, M, N;
	scanf("%d", &T);
	while(T){
		memset(dist, -1, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &N, &M);
//		printf("input done!\n");
		int x1, x2;
		for(int i=0; i<M; i++){
			scanf("%d%d", &x1, &x2);
			graph[x1].push_back(x2);
			graph[x2].push_back(x1);
		}
		
		queue <int> Q;
		Q.push(1);
		dist[1]=0;
		vis[1]=1;
//		printf("graph start\n");
		while(!Q.empty()){
			int parent= Q.front();
			Q.pop();
			
			for(ll i=0; i<graph[parent].size(); i++){
				int child= graph[parent][i];
				
				if(vis[child])
					continue;
				vis[child]=1;
									
				if(dist[child]==-1 || dist[child]>dist[parent]+1)
					dist[child]=dist[parent]+1;
				
				Q.push(child);
			}
		}
		printf("%d\n", dist[N]);
		
		T--;
	}
	return 0;
}
