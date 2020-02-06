#include <bits/stdc++.h>
#define maxl (int)(1e5+7)
using namespace std;
int n;
int arr[maxl], dpmin[maxl], dpmax[maxl];
bool ismax(int i){
	if(i==1||i==n) return 0;
	return (arr[i]>arr[i+1]&&arr[i]>arr[i-1]);
}
bool ismin(int i){
	if(i==1||i==n) return 0;
	return (arr[i]<arr[i+1]&&arr[i]<arr[i-1]);
}
bool check(int l, int r){
	int mins= dpmin[r]-dpmin[l];
	if(ismin(r)) mins-=1;
	int maxs= dpmax[r]-dpmax[l];
	if(ismax(r)) maxs-=1;
	int temp= maxs-mins;
	//printf("[%d %d] %d ", mins, maxs, temp);
	if(temp==1) if(arr[l]<arr[l+1]&&arr[r]<arr[r-1]) return 1;
	if(temp==-1) if(arr[l]>arr[l+1]&&arr[r]>arr[r-1]) return 1;
	return 0;		
}
int main(){
	int q;
	scanf("%d%d", &n ,&q);
	//scanf("%d", &n);
	for(int i=1; i<n+1; i++) scanf("%d", arr+i);
	int mins=0, maxs=0;
	for(int i=2; i<=n-1; i++){
		if(ismin(i)) mins+=1;
		if(ismax(i)) maxs+=1;
		dpmax[i]=maxs; dpmin[i]=mins;
	}
	dpmax[1]=0; dpmin[1]=0; dpmax[n]=maxs; dpmin[n]=mins;	
	//for(int i=1; i<=n; i++)
		//printf("%d:{%d %d} ", i, dpmin[i], dpmax[i]);
	//printf("\n");	
	int l, r;
	while(q--){
		scanf("%d%d", &l, &r);
		if(check(l,r)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
