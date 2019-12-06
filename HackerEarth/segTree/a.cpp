#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define R(i,a,b) for(int i=(int)(a); i>(int)(b); i--)
#define maxl 100000
using namespace std;
int tree[2*maxl];
int arr[maxl];
int query(int, int, int, int, int);
void update(int, int, int, int, int);
void build(int, int, int);
int n;
int main() {
	char k;
	int l,r,p,val;
	int q;
	scanf("%d%d", &n, &q);
	F(i,1,n+1)
		scanf("%d", arr+i);
	build(1,1,n);
	F(i,0,q) {
		scanf("\n%c", &k);
		if(k=='q') {
			scanf("%d%d", &l, &r);
			printf("%d\n", query(1,1,n,l,r));
		}
		else {
			scanf("%d%d", &p, &val);
			arr[p]=val;
			update(1, 1, n, p, val);
		}
	}
	return 0;
}
void build(int index, int start, int end) {
	if(start==end) {
		tree[index]=arr[start];
		return;
	}
		
	int mid=(start+end)/2;
	build(2*index, start, mid);
	build(2*index+1, mid+1, end);
	
	tree[index]= min(tree[2*index],tree[2*index+1]);
}
int query(int index, int start, int end, int l, int r) {
	if(l>end||r<start)
		return maxl+1;
	if(l<=start&&r<=end)
		return tree[index];
	
	int mid=(start+end)/2;
	int lquery= query(2*index, start, mid, l, r);
	int rquery= query(2*index+1, mid+1, end, l, r);
	
	return min(lquery, rquery);	
}
void update(int index, int start, int end, int idx, int val) {
	if(start==end) {
		tree[index]=val;
		return;
	}
	
	int mid=(start+end)/2;
	if(start<=idx && idx<=mid) 
		update(2*index, start, mid, idx, val);
	else
		update(2*index+1, mid+1, end, idx, val);
	
	tree[index]= min(tree[2*index], tree[2*index+1]);		
}
