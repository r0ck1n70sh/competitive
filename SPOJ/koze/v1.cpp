#include <bits/stdc++.h>
#define maxl 256
#define PII pair<int, int>
using namespace std;

char field[maxl][maxl];
bool vis[maxl][maxl];
int N, M;

void bfs(int*, int*, int, int);
bool valid(int ,int);
bool escape(int, int);
int main(){
	scanf("%d%d\n", &N, &M);
	memset(vis, 0, sizeof(vis));
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			scanf("%c", &field[i][j]);
			if(field[i][j]=='#')
				vis[i][j]=1;
		}
		if(i!=N-1)
			scanf("\n");
	}
	
/*	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++)
			printf("%c", field[i][j]);
		printf("\n");
	}
*/	
	int sheep=0, wolf=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(vis[i][j])
				continue;
			bfs(&sheep, &wolf, i, j);
	//		printf("S:%d W:%d i:%d j:%d \n", sheep, wolf, i, j);
		}
	}
	printf("%d %d\n", sheep, wolf);
	return 0;
}

void bfs(int *S, int *W, int r, int c){
	int sheep=0, wolf=0;
	array<PII, 2> arr={ {{1,0},{0,1}} };
	
	queue<PII> q;
	q.push({r,c});
	bool flag=0;
	while(!q.empty()){
		int i= q.front().first;
		int j= q.front().second;
		q.pop();
		
		if(escape(i,j))
			flag=1;
		
		if(vis[i][j])
			continue;
		vis[i][j]=1;
		
		if(field[i][j]=='k') {
			++sheep;
//			printf("sheep:%d %d\n", i, j);
		}
		else if(field[i][j]=='v') {
			++wolf;
//			printf("wolf:%d %d\n", i, j);
		}
			
		for(int k=0; k<2; k++) {
			int x=arr[k].first, y=arr[k].second;
			if(valid(x+i, y+j) && !vis[i+x][j+y]) {
				q.push({i+x, j+y});
			}
		}
	}
	
	if(sheep>wolf && !flag)
		wolf=0;
	else if(!flag)
		sheep=0;
		
	(*S)+=sheep;
	(*W)+=wolf;	
}

bool valid(int x, int y) {
	if(x>=0 && x<N && y>=0 && y<M)
		return 1;
	return 0;
}
bool escape(int x, int y) {
	if(x==0 || x==N-1)
		return true;
	if(y==0 || y==M-1)
		return true;
	return false;
}
