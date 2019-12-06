#include <bits/stdc++.h>
#define maxl 1000000+1
#define ll long long int
using namespace std;
const int MOD=1e9+7;
ll inline mod(ll x) {
	return (x%MOD+MOD)%MOD;
}
void computePhi();
void computePillai();
ll query(int);
void update(int, ll);
ll arr[maxl];
ll bit[maxl], p[maxl], phi[maxl];
int N;
int main() {
	computePhi();
	computePillai();
	memset(bit, 0, sizeof(bit));
	
	char q;
	int Q;
	int x, y;
	scanf("%d", &N);
	for(int i=1; i<N+1; i++) {
		scanf("%lld", arr+i);
		update(i, p[arr[i]]);
	}
	scanf("%d", &Q);
	while(Q) {
		scanf("\n%c%d%d", &q, &x, &y);
		if(q=='C')
			printf("%lld\n", mod(query(y)-query(x)+p[arr[x]]));
		else {
			update(x, p[y]-p[arr[x]]);
			arr[x]=y;
		}
		--Q;
	}
	return 0;
}
void computePhi() {
	for(int i=1; i<maxl; i++)
		phi[i]=i;
	for(int i=2; i<maxl; i++)
		if(phi[i]==i) {
			for(int j=i; j<maxl; j+=i) {
				phi[j]-= phi[j]/i;
			}
		}
}
void computePillai() {
	for(int i=1; i<maxl; i++)
		for(int j=i; j<maxl; j+=i)
			p[j] = mod(mod(p[j])+mod(i*phi[j/i]));
}
ll query(int x) {
	ll sum=0;
	for(;x>0;x-=(x&(-x)))
			sum= mod(sum+bit[x]);
	return sum;
}
void update(int x, ll value) {
	for(;x<N+1;x+=(x&(-x)))
		bit[x]=mod(mod(bit[x])+mod(value));
}
