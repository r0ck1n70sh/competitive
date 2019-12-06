#include <bits/stdc++.h>
#define max1 10000+1
#define max 1000000+1
std::vector<std::pair<int, int>> V[max1];
bool vis[max1];
int dist[max1];
int main(){
	int n, m;
	int x, y, w;
	std::pair<int, int> curr;
	std::multiset<std::pair<int, int>> S;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++) {
		scanf("%d%d%d", &x, &y, &w);
		V[x].push_back({w, y});
	}
	memset(vis, false, sizeof(bool)*max1);
	memset(dist, max1, sizeof(int)*max1);
	
	S.insert({0, 1});
	dist[1]=0;
	
	while(!S.empty()) {
		curr=*(S.begin());
		S.erase(S.begin());
		x=curr.second ;w=curr.first;
		if(vis[x])
			continue;
		for(unsigned long int i=0; i<V[x].size(); i++) {
			int child=V[x][i].second ; int weigh=V[x][i].first;
			if(dist[child]>weigh+dist[x]) {
				dist[child]=weigh+dist[x];
				S.insert({dist[child], child});
			}
		}
		vis[x]=true;
	}	
	for(int i=2; i<n+1; i++)
		printf("%d ", dist[i]);
	printf("\n");
	
	return 0;
}
