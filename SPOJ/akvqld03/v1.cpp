#include <bits/stdc++.h>
#define ll long long unsigned int
#define maxl (int)(1e6+6)
using namespace std;

ll N, Q;
ll *tree;

void update(ll, ll, ll, ll, ll);
ll query(ll, ll, ll, ll, ll);

int main(){
	scanf("%lld%lld", &N, &Q);
	string q;
	ll n1= 2*N+10;
	tree= (ll*)calloc(n1, sizeof(ll));
	
	while(Q){
		ll x, y;
		cin>>q>>x>>y;
		
		if(q=="find")
			printf("%lld\n", query(1,N,1,x,y));
			
		else
			update(1,N,1,x,y);
			
		--Q;
	}
	delete [] tree;
	return 0;
}

void update(ll s, ll e, ll n, ll idx, ll val) {
	if(s==e) {
		tree[n]+=val;
		return;
	}
	
	ll m=(s+e)/2;
	
	if(idx<=m)
		update(s, m, 2*n, idx, val);
	else
		update(m+1, e, 2*n+1, idx, val);
	
	tree[n]= tree[2*n]+ tree[2*n+1];
}

ll query(ll s, ll e, ll n, ll l ,ll r) {
	if(r<s||l>e)
		return 0;
		
	if(s>=l && e<=r)
		return tree[n];
	
	ll m= (s+e)/2;
	return query(s,m,2*n,l,r) + query(m+1,e,2*n+1,l,r);
}
