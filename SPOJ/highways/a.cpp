#include <bits/stdc++.h>
#define maxl 100001
#define ll unsigned int
#define PII pair<ll, int>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
using namespace std;
array<vector<PII>, maxl> V;
bool vis[maxl];
ll dist[maxl];
void dijkstra(int);
int main() {
	int t;
	int s, e, n, m;
	scanf("%d", &t);
	while(t) {
		int x, y;
		ll d;
		scanf("%d%d%d%d", &n, &m, &s, &e);
		F(i,0,m) {
			scanf("%d%d%u", &x, &y, &d);
			V[x].push_back({d, y});
			V[y].push_back({d, x});
		}
		dijkstra(s);
		if(dist[e]<(ll)(-1))
			printf("%u\n", dist[e]);
		else
			printf("NONE\n");
		--t;
	}
	return 0;
}
void dijkstra(int src) {
	memset(vis, 0, sizeof vis);
	memset(dist, -1, sizeof dist);
	
	dist[src]=0;
	multiset <PII> Q;
	Q.insert({0,src});
	
	while(!Q.empty()) {
		PII curr=*(Q.begin());
		Q.erase(Q.begin());
		
		int x=curr.second;
		if(vis[x]) continue;
		vis[x]=1;
		
		F(i,0,V[x].size()) {
			int child=V[x][i].second;
			int edge=V[x][i].first;
			if(dist[child]>dist[x]+edge) {
				dist[child]=dist[x]+edge;
				Q.insert({dist[child], child});
			}
		}
	}
}
