#include <bits/stdc++.h>
using namespace std;
int vis[10], p[10], arr[10];
int solve(int idx, int sum, int k){
	//for(int i=0;i<=9;i++) printf("%d ",p[i]);
			//printf("\n");
	if(idx>9&&sum<=k) return 1; 
	if(sum>k) return 0;
	//if(sum+arr[idx]>k) return 0;
	for(int i=0;i<=9;i++){
		if(vis[i]) continue;
		vis[i]=1; p[idx]=i;
		if(solve(idx+1,sum+i*arr[idx],k)) return 1;
		vis[i]=0;
	}
	return 0;
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		for(int i=0;i<=9;i++) scanf("%d",&arr[i]);
		int k; scanf("%d",&k);
		memset(vis,0,sizeof(vis)); memset(p,-1,sizeof(p));
		if(solve(0,0,k)){
			for(int i=0;i<=9;i++) printf("%d ",p[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
