#include <bits/stdc++.h>
#define maxl (int)(2e3+4)
using namespace std;
array<vector<int>, maxl> graph;
int c[maxl];
int main(){
	int n;
	int pi, ci. root; 
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d%d", pi, ci);
		c[i]=ci;
		if(pi==0){
			root=i
			continue;
		}
		graph[pi].push_back(i);
	}
	
	if(!check(root));
	return 0;
}
