#include <bits/stdc++.h>
#define max1 500000+5
#define max 1000000
#define INF 1e9
void dijktra(int s);
std::vector<std::pair<int, int>> V[max1];
int dist[max1];
bool vis[max1];
int N, M;
int main() {
	int Q, count=0, mostDist=0;
	int x, y, l, q;
	scanf("%d%d%d", &N, &M, &Q);
	for(int i=0; i<M; i++) {
		scanf("%d%d%d", &x, &y, &l);
		V[x].push_back({l, y});
		V[y].push_back({l, x});
	}

	for(int j=0; j<Q; j++) {
		scanf("%d", &q);
		dijktra(q);
		count=0; mostDist=0;
		for(int i=0; i<N; i++) {
		//	printf("%d ", dist[i]);
			if((dist[i]>mostDist)&&(dist[i]<INF)) {
				mostDist=dist[i];
				count=1;
			}
			else if(dist[i]==mostDist)
				count++;
		}
		printf("%d %d\n", mostDist, count);
	}
	return 0;
}
void dijktra(int s) {
	int child, length, x;
	std::pair<int, int> curr;
	std::multiset<std::pair<int, int>> S;
//	memset(dist, 11, sizeof(int)*N);
	for(int i=0; i<N; i++)
		dist[i]=INF;
//	memset(vis, false, sizeof(bool)*N);
	for(int i=0; i<N; i++)
		vis[i]=false;
	
	S.insert({0, s});
	dist[s]=0;
	while(!S.empty()) {
		curr=*(S.begin());
		S.erase(S.begin());
		x=curr.second;
		if(vis[x])
			continue;
		vis[x]=true;
		for(unsigned int i=0; i<V[x].size(); i++) {
			child=V[x][i].second; length=V[x][i].first;
			if(dist[x]+length<dist[child]) {
				dist[child]=dist[x]+length;
				S.insert({dist[child], child});
			}
		}
	}
}

