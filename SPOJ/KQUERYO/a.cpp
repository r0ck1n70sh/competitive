#include <bits/stdc++.h>
using namespace std;
const int maxl= 3e4+4;
int arr[maxl], n;
vector<int> tree[3*maxl];
void build(int node,int lo,int hi){
	if(hi==lo){
		tree[node].push_back(arr[lo]); return;
	}
	int mid= (lo+hi)/2;
	build(2*node,lo,mid); build(2*node+1,mid+1,hi);
	tree[node].resize(tree[2*node].size()+tree[2*node+1].size());
	merge(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),tree[2*node+1].end(), tree[node].begin());	
}
int cnt(int node,int lo,int hi,int x,int y,int k){
	if(lo>y||hi<x) return 0;
	if(lo>=x&&hi<=y)
		return tree[node].end()-upper_bound(tree[node].begin(),tree[node].end(),k);
	int mid=(hi+lo)/2;
	return cnt(2*node,lo,mid,x,y,k)+cnt(2*node+1,mid+1,hi,x,y,k);
}
int main(){
	int q; scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d", arr+i);
	scanf("%d",&q); build(1,1,n); //printf("running\n");
	for(int i=0, prv=0;i<q;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		l^=prv, r^=prv, k^=prv; //printf("%d %d %d\n",l,r,k);
		if(l<1) l=1; if(r>n) r=n;
		if(l<=r){
			//printf("%d %d %d\n",l,r,k);
			prv=cnt(1,1,n,l,r,k);
		}
		else prv=0;
		printf("%d\n", prv);
	}
}
