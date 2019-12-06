#include <bits/stdc++.h>

int main() {
	int f, s, g, u, d;
	std::queue<int> S;
	int *level;
	int child[2];
	bool *vis;
	int p;
	scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
	child[0]=u; child[1]=-d;
	vis=(bool*)malloc(sizeof(bool)*f);
	memset(vis, false, f*sizeof(bool));
	level=(int*)malloc(sizeof(int)*f);
	memset(level, -1, f*sizeof(int));
	
	S.push(s-1);
	level[s-1]=0;
	vis[s-1]=true;
	while(!S.empty()){
		p=S.front();
		if(p==(g-1))
			break;
		S.pop();
		for(int i=0; i<2; i++) {
			if((p+child[i]>f-1)||(p+child[i]<0))
				continue;			
			if(!vis[p+child[i]]) {
				S.push(p+child[i]);
				vis[p+child[i]]=true;
				level[p+child[i]]=level[p]+1;
			}
		}
	}
	
	if(level[g-1]<0)
		printf("use the stairs");
	else
		printf("%d\n", level[g-1]);
	free(vis); free(level);
		
	return 0;
}
