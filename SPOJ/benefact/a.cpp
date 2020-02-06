#include <bits/stdc++.h>
#define maxl (int)(5e5+5)
#define PII pair<int, int>
#define F first
#define S second
using namespace std;
int n;
array<vector<PII>, maxl> graph;
int dist[maxl];
bool vis[maxl];
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		int x, y, l;
		scanf("%d", &n);
		for(int i=0; i<n-1; i++){
			scanf("%d%d%d", &x, &y, &l);
			graph[x].push_back({y,l});
			graph[y].push_back({x,l});
		}
		
		memset(vis, 0, sizeof(vis));
		memset(dist, -1, sizeof(dist));
		queue<int> q;
		int s=1;
		dist[s]=0;
		q.push(s);
		while(!q.empty()){
			int par=q.front();
			q.pop();
			//if(vis[par.F])
				//continue;
			vis[par]=1;
			for(size_t i=0; i<graph[par].size(); i++){
				int child= graph[par][i].F;
				if(vis[child])
					continue;
				dist[child]= dist[par]+graph[par][i].S;
				q.push(child);
			}
		}
		int curr, maxd=0;
		for(int i=1; i<=n; i++)
			if(dist[i]>maxd) {
				curr=i;
				maxd=dist[i];
			}
		//printf("%d %d\n", maxd, curr);
		
		memset(vis, 0, sizeof(vis));
		memset(dist, -1, sizeof(dist));
		s=curr;
		q.push(s);
		dist[s]=0;
		while(!q.empty()){
			int par=q.front();
			q.pop();
			//if(vis[par.F])
				//continue;
			vis[par]=1;
			for(size_t i=0; i<graph[par].size(); i++){
				int child= graph[par][i].F;
				if(vis[child])
					continue;
				dist[child]= dist[par]+graph[par][i].S;
				q.push(child);
			}
		}
		maxd=0, curr=0;
		for(int i=1; i<=n; i++)
			if(dist[i]>maxd){
				curr=i;
				maxd=dist[i];
			}
		printf("%d\n", maxd);
			
		for(int i=0; i<=n; i++)
				graph[i].clear();
	}
	return 0;
}
