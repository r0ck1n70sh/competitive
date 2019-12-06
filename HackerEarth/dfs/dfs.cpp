#include <bits/stdc++.h>
#define max 100000
int dfsCount(const std::array<std::vector<int>, max> &V, int s, int n);
void initialize(bool *arr, int size);
int main(){
	int n, m, x, y;
	std::array<std::vector<int>, max> V;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		V[x].push_back(y);
		V[y].push_back(x);
	}
	scanf("%d", &x);
	y=dfsCount(V, x, n);
	printf("%d\n", n-y);
}
int dfsCount(const std::array<std::vector<int>, max> &V, int s, int n) {
	int count=1, p;
	bool vis[n];
	std::stack<int> S;
	
	initialize(vis, n);
	S.push(s);
	vis[s]=true;
	while(!S.empty()) {
		p=S.top();
		S.pop();
		for(int i=0; i<V[p].size(); i++) {
			if(!vis[V[p][i]]) {
				vis[V[p][i]]=true;
				S.push(V[p][i]);
				count++;
			}
		}
	}
	return count;
}
void initialize(bool *arr, int size) {
	for(int i=0; i<size; i++)
		arr[i]=false;
}
