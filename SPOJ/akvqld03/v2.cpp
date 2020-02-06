//Fedwick Tree Approach

#include <bits/stdc++.h>
#define ll long long int
#define maxl 1000000+100
using namespace std;

ll bit[maxl];
int N, Q;

void update(ll, ll);
ll getSum(ll);

int main(){
	string S;
	scanf("%d%d", &N, &Q);
	memset(bit, 0, sizeof(bit));
	
	while(Q){
		cin>>S;
		if(S=="find") {
			ll l, r;
			cin>>l>>r;
			printf("%lld\n", getSum(r-1)-getSum(l-2));
		}
		else{
			ll p, val;
			cin>>p>>val;
			update(p-1, val);
		}
		--Q;
	}	
	return 0;
}

ll getSum(ll p) {
	ll sum=0;
	
	for(ll x=p+1 ;x>0; x-=(x&(-x)))
		sum+=bit[x];
	
	return sum;
}

void update(ll p, ll val) {
	
	for(ll x=p+1 ;x<=N; x+=(x&(-x)))
		bit[x]+=val;
}
