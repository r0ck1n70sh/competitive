#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
vector<int>p;
vector<vector<int>>v;
pair<int,int> dfs(int node,int par,int dist){
	p[node]=par; //cout<<node<<"\n";
	pair<int,int> res={dist,node};
	for(auto to:v[node]){
		if(to==par) continue;
		res=max(res,dfs(to,node,dist+1));
	}
	return res;
}
int main(){
	int n; scanf("%d",&n);
	p.resize(n); v.resize(n);
	for(int i=0;i<n-1;i++){
		int x,y; scanf("%d%d",&x,&y);--x;--y;
		v[x].push_back(y); v[y].push_back(x);
	} //cout<<"22\n";
	pair<int,int> da=dfs(0,-1,0); pair<int,int> db=dfs(da.y,-1,0);
	vector<int> diam; int node=db.y; //cout<<"24\n";
	while(node!=da.y){
		diam.push_back(node); node=p[node];
	} //cout<<"27\n";
	diam.push_back(da.y);
	if(int(diam.size())==n){
		printf("%d\n%d %d %d\n",n-1,diam[0]+1,diam[1]+1,diam[n-1]+1);
		return 0;
	}
	queue<int> q; vector<int> d(n,-1);
	for(auto node:diam){ d[node]=0; q.push(node);}
	while(!q.empty()){
		int node=q.front(); q.pop();
		for(auto to:v[node]){
			if(d[to]!=-1) continue;
			d[to]=d[node]+1; q.push(to);
		}
	}
	pair<int,int> mx={d[0],0};
	for(int node=1;node<n;node++) mx=max({mx, {d[node],node}});
	printf("%d\n%d %d %d\n",int(diam.size())+mx.x-1,mx.y+1,diam[0]+1,diam.back()+1);
	return 0;
}
