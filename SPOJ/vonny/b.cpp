#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
typedef pair<int, int> ii;

int t, n=7, m=8, ans, box[10][10], taken[10][10];
bool vis[10][10];

bool valid(int, int);
ii get(int, int);
void solve(int, int);

int main() {
	scanf("%d", &t);
	while(t) {
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				scanf("%d", &box[i][j]);
		ans=0;
		memset(vis, false, sizeof vis);
		memset(taken, 0, sizeof taken);
		solve(1,1);
		printf("%d\n", ans);
		t--;
	}
	return 0;
}

bool valid(int x, int y) {
	if(x>n||y>m)
		return 0;
	if(taken[x][y])
		return 0;
	return 1;
}

ii get(int x, int y) {
	if(y>m) {
		++x;
		y=1;
	}
	return ii(x,y);
}

void solve(int x, int y) {
	if(x>n) {
		ans++;
		return;
	}	
	ii temp;
	if(taken[x][y]) {
		temp=get(x, y+1);
		solve(temp.first, temp.second);
		return;
	}
	taken[x][y]=1;
	int p,q;
	if(valid(x, y+1)) {
		p=box[x][y];
		q=box[x][y+1];
		if(p>q)
			swap(p,q);
		if(!vis[p][q]) {
			vis[p][q]=1;
			taken[x][y+1]=1;
			temp=get(x, y+2);
			solve(temp.first, temp.second);
			vis[p][q]=0;
			taken[x][y+1]=0;
		}
	}
	if(valid(x+1, y)) {
		p=box[x][y];
		q=box[x+1][y];
		if(p>q)
			swap(p,q);
		if(!vis[p][q]) {
			vis[p][q]=1;
			taken[x+1][y]=1;
			temp=get(x, y+1);
			solve(temp.first, temp.second);
			vis[p][q]=0;
			taken[x+1][y]=0;
		}
	}
	taken[x][y]=0;
}
