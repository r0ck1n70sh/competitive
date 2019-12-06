#include <bits/stdc++.h>
#define maxl 10001
#define PII pair<int,int>
#define ll unsigned int
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
using namespace std;
array<vector<PII>, maxl> g;
int INF=1000001;
int dist[maxl];
bool vis[maxl];
void dij();
int main() {
	int n, m;
	int x, y;
	ll d;
	scanf("%d%d", &n, &m);
	F(i,0,m) {
		scanf("%d%d%d", &x, &y, &d);
		g[x].push_back({d,y});
	}
	F(i,1,n+1)
		dist[i]=INF;
	dij();
	F(i,2,n+1)
		printf("%d ", dist[i]);
	printf("\n");
	return 0;
}
void dij() {
	memset(vis, 0, sizeof vis);
	dist[1]=0;
	multiset <PII> s;
	s.insert({0,1});
	
	while(!s.empty()) {
		PII p=*(s.begin());
		s.erase(s.begin());
		
		int x=p.second;
		if(vis[x]) continue;
		vis[x]=true;
		for(ll i=0; i<g[x].size(); i++) {
			int child=g[x][i].second; int weigh=g[x][i].first;
			if(dist[child]>dist[x]+weigh) {
				dist[child]=dist[x]+weigh;
				s.insert({dist[child],child});
			}
		}
	}
}
