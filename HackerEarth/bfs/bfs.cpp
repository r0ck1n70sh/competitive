#include <bits/stdc++.h>
#define max 100000
void intialize(bool *arr, int n);
int main() {
	int n, x, y, s, p;
	int level[max];
	bool vis[max];
	std::vector<int> v[max];
	std::queue<int> q;
	
	scanf("%d", &n);
	for(int i=0; i<n-1; i++) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y); v[y].push_back(x);
	}
	scanf("%d", &x);
	y=0;
	intialize(vis, n);
	s=1;
	q.push(s);
	level[s]=1;
	vis[s]=true;
	while(!q.empty()) {
		p=q.front();
		q.pop();
		for(long unsigned int i=0; i<v[p].size(); i++) {
			if(!vis[v[p][i]]) {
				level[v[p][i]]=level[p]+1;
				q.push(v[p][i]);
				vis[v[p][i]]=true;
			}
		}
	}
	for(int i=0; i<n; i++)
		if(level[i]==x)
			y++;
	printf("%d\n", y);
	
	return 0;
}
void intialize(bool *arr, int n) {
	for(int i=0; i<n; i++)
		arr[i]=false;
}
