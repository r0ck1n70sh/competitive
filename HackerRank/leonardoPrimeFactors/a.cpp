#include <bits/stdc++.h>
#define maxl 1e5
#define ll long long unsigned int
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
using namespace std;
bool sieve[100000];
vector<int> prime;
void generatePrime();
ll uniquePrime(ll);
int main() {
    int q;
    ll n;
    generatePrime();
    scanf("%d", &q);
    while(q) {
        scanf("%llu", &n);
        printf("%llu\n", uniquePrime(n));
        --q;
    }
    return 0;
}
void generatePrime() {
    int limit=floor(sqrt(maxl))+1;
    memset(sieve, 0, sizeof sieve);
	F(i,2,limit) {
		if(sieve[i]==0) {
			prime.push_back(i);
			for(int p=i; p<limit; p+=i)
				sieve[p]=1;
		}
	}
	int low=limit;
	int high=2*limit;
	
	while(low<maxl) {
		if(high>=maxl)
			high=maxl;
		memset(sieve, 0, sizeof sieve);
		
		for(ll i=0; i<prime.size(); i++) {
			int loLim=floor(low/prime[i])*prime[i];
			if(loLim<low)
				loLim+=prime[i];
			
			for(int j=loLim; j<high; j+=prime[i])
				sieve[j-low]=0;
		}
		for(int i=low; i<high; i++)
			if(sieve[i-low])
				prime.push_back(i);
		
		low+=limit;
		high+=limit;
	}	
}
ll uniquePrime(ll n) {
	ll count=0, maxPf=1;
	F(i,0,prime.size()) {
		maxPf*=prime[i];
		if(maxPf>n)
			break;
		count++;
	}
	return count;
}
