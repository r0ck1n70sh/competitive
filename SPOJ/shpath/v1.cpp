#include <bits/stdc++.h>
#define maxl 10010
#define ll long unsigned int
#define PII pair<ll ,int>
using namespace std;

array<vector<PII>, maxl> graph;
map<string, int> idx;
bool vis[maxl];
ll dist[maxl];

ll dijkstra(int ,int);
int main(){
	int T, N;
	scanf("%d", &T);
	while(T){
		scanf("%d", &N);
		int nr, y;
		ll w;
		string city;
		for(int x=1; x<N+1; x++) {
			cin>>city;
			idx.insert({city, x});
			scanf("%d", &nr);
			for(int i=0; i<nr; i++)	{
				scanf("%d%lu", &y, &w);
				graph[x].push_back({w, y});
			}
		}
		int r;
		scanf("%d", &r);
		while(r){
			string c1, c2;
			cin>>c1>>c2;
			printf("%lu\n", dijkstra(idx[c1], idx[c2]));
			--r;
		}
		for(int i=1; i<N+1; i++)
			graph[i].clear();
		--T;
	}	
	return 0;
}

ll dijkstra(int s, int d){
	memset(vis, 0, sizeof(vis));
	memset(dist, -1, sizeof(dist));

	priority_queue<PII, vector<PII>, greater<PII>> Q;
	dist[s]=0;
	Q.push({0, s});
	
	while(!Q.empty()){
		int parent= Q.top().second;
		Q.pop();
		
		if(parent==d)
			break;
					
		if(vis[parent])
			continue;
		vis[parent]=1;
		
		for(int i=0; i<graph[parent].size(); i++){
			int child= graph[parent][i].second;
			int edge= graph[parent][i].first;
			
			if(dist[child]>dist[parent]+edge)
				dist[child]= dist[parent]+edge;
			
			Q.push({dist[child], child});
		}
	}
	return dist[d];	
}
