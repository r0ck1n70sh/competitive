#include <bits/stdc++.h>
#define maxl 200
#define PPI pair<int,int>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
int G[maxl+1][maxl+1]
int P, Q, x1, y1, x2, y2;
int bfs();
int main() {
	int T ,ans;
	scanf("%d",&T);
	while(T) {
		scanf("%d%d",&P,&Q);
		F(i,1,P+1)
			F(j,1,F+1)
				scanf("%d",&G[i][j]);
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		ans=bfs();
		if(ans>=0)
			printf("The shortest path is %d steps long.\n");
		else
			printf("Mission Impossible!\n");
		T--;
	}
	return 0;
}
int bfs() {
	stack<PII> S;
	bool vis[maxl+1][maxl+1];
	memset(vis, 0, sizeof vis);
	
	if(x1==x2&&y1==y2)
		return 0;
	
	
	
}
