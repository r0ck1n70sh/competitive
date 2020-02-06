#include <bits/stdc++.h>
#define maxl 100
#define mod (int)(1e9+7)
using namespace std;
int n;
int arr[maxl];
bool vis[maxl];
bool check(){
	int s=0, e=0, l=n-1;
	for(int i=n-1; i>=0; i--)
		if(!vis[i]){
			l=i;
			break;
		}
	//while(e<l){
	for(int idx=0; idx<n&&e<l; idx++){
		for(int i=((idx==0)?0:e+1); i<n; ++i){
			if(!vis[i]){
				s=i;
				break;
			}
		}
		for(int i=s+1; i<n+1; ++i){
			e=i;
			if(vis[i])
				break;
		}
		for(int i=s; i<e-1; i++)
			if(arr[i]>arr[i+1])
				return 0;				
	}
	//for(int i=0; i<n; i++)
		//printf("%d ", vis[i]);
	//printf("\n");
	return 1;
}
int solve(int idx){
	if(idx==n){
		if(check())
			return 1;
		else
			return 0;
	}
	int res=0;
	vis[idx]=1;
	res+=(solve(idx+1))%mod;
	vis[idx]=0;
	res=(res+solve(idx+1)%mod)%mod;
	return res;
}
int main(){
	memset(vis, 0, sizeof(vis));
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	printf("%d\n", solve(0));
	return 0;
}
