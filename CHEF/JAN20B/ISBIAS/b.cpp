#include <bits/stdc++.h>
using namespace std;
const int maxl= (int)(1e5+3);
int arr[maxl], tree[2*maxl];
int n;
bool ismin(int idx){
	if(idx==1||idx==n) return 0; 
	return (arr[idx]<arr[idx+1])&&(arr[idx]<arr[idx-1]);
}
bool ismax(int idx){
	if(idx==1||idx==n) return 0; 
	return (arr[idx]>arr[idx+1])&&(arr[idx]>arr[idx-1]);
}
int build(int node, int s, int e){
	if(s==e) return tree[node]=0;
	int mid=(s+e)/2, res=0;
	if(mid!=s&&mid!=e&&mid+1!=s&&mid+1!=e) {
		if(ismin(mid)||ismin(mid+1)) res-=1;
		if(ismax(mid)||ismax(mid+1)) res+=1;
	}
	return tree[node]=build(2*node,s,mid)+build(2*node+1,mid+1,e)+res;
}
int query(int node, int s, int e, int l, int r){
	if(e<=l||r<=s) return 0;
	if(s>l&&r>e) return tree[node];
	int mid=(s+e)/2, res=0;
	if(mid!=s&&mid!=e&&mid+1!=s&&mid+1!=e) {
		if(ismin(mid)||ismin(mid+1)) res-=1;
		if(ismax(mid)||ismax(mid+1)) res+=1;
	}
	return query(2*node,s,mid,l,r)+query(2*node+1,mid+1,e,l,r)+res;
}
bool check(int l, int r){
	int res=query(1,1,n,l,r); printf("res:%d\n", res);
	if(res==-1) if(arr[l]>arr[l+1]&&arr[r]>arr[r-1]) return 1;
	if(res==1) if(arr[l]<arr[l+1]&&arr[r]<arr[r-1]) return 1;
	return 0;
}
int main(){
	int q;	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d", arr+i);
	build(1,1,n);
	while(q--){
		int l,r; scanf("%d%d", &l, &r);
		if(check(l,r)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
