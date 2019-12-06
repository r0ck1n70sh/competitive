#include <bits/stdc++.h>
#define maxl 100000+1
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define R(i,a,b) for(int i=(int)(a); i>(int)(b); i--)
using namespace std;

void build(int,int,int);
void update(int, int, int, int, int);
int query(int, int, int, int, int);

int tree[2*maxl+1];
int arr[maxl];

int main() {
	char k;
	int n, q, f, r;
	memset(arr, -1, sizeof arr);
	scanf("%d%d", &n, &q);
	F(i,0,n)
		scanf("%d", arr+i);
	build(1,0,n-1);
	while(q) {
		scanf("\n%c%d%d", &k, &f, &r);
		if(k=='q')
			printf("%d\n", query(1,0,n-1,f-1, r-1));
		else
			update(1,0,n-1,f-1,r);
		--q;
	}
	return 0;
}

void build(int i, int s, int e) {
	if(s==e) {
		tree[i]=arr[s];
		return;
	}
	int m=(s+e)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, e);
	
	tree[i]=min(tree[2*i],tree[2*i+1]);
}

void update(int i, int s, int e, int idx, int val) {
	if(s==e) {
		tree[i]=val;
		arr[idx]=val;
		return;
	}
		
	int m=(s+e)/2;
	if(s<=idx&&m>=idx)
		update(2*i, s, m, idx, val);
	else
		update(2*i+1, m+1, e, idx, val);
		
	tree[i]= min(tree[2*i], tree[2*i+1]);	
}

int query(int i, int s, int e, int l, int r) {
	if(l<=s&&r>=e)
		return tree[i];
	if(s>r||e<l)
		return maxl+1;
			
	int m=(s+e)/2;
	int lquery= query(2*i, s, m, l, r);
	int rquery= query(2*i+1, m+1, e, l, r);
	
	return min(lquery, rquery);
}
