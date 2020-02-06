#include <bits/stdc++.h>
using namespace std;
const int maxl= (int)(1e5+3);
vector<int> v[maxl];
bool vis[maxl];
int dfs(int root){
	if(vis[root]) return 0;
	vis[root]=1;
	for(int i=0; i<v[root].size(); i++) dfs(v[root][i]);
	return 1;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, e;
		scanf("%d%d", &n, &e);
		for(int i=0,x,y; i<e; i++){
			scanf("%d%d", &x, &y); v[x].push_back(y); v[y].push_back(x);
		}
		memset(vis, 0, sizeof(vis)); int res=0;
		for(int i=0; i<n; i++) res+=dfs(i);
		printf("%d\n", res); for(int i=0; i<n; i++) v[i].clear();
	}
	return 0;
}
