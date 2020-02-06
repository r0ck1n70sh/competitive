#include <bits/stdc++.h>
#define maxl 2005
using namespace std;
int n, c[maxl], res[maxl];
vector<int> graph[maxl], q;
int dfs(int node){
	int res=(node>0);
	for(size_t i=0; i<graph[node].size();i++)
		res+=dfs(graph[node][i]);
	if(node){
		if(res<=c[node]){
			printf("NO\n");
			exit(0);
		}
		q.insert(q.begin()+c[node], node);
	}
	return res;
}
int main(){
	scanf("%d", &n);
	for(int i=1, x; i<=n; i++){
		scanf("%d%d", &x, &c[i]);
		graph[x].push_back(i);
	}
	dfs(0);
	for(size_t i=0; i<q.size(); i++)
		res[q[i]]=i+1;
	printf("YES\n");
	for(int i=1; i<=n; i++)
		printf("%d ", res[i]);
	printf("\n");
	return 0;
}
