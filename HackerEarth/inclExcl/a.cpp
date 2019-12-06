#include <bits/stdc++.h>
#define ll long long unsigned int
using namespace std;
ll divisors[]={2,3,11,13};
ll n;
ll gcd(ll, ll);
ll unionCardinality();
ll intersectionCardinality(vector<int>&);
int main() {
	scanf("%llu", &n);
	ll p= unionCardinality();
	ll g= gcd(n,p);
	p/=g; n/=g;
	printf("%llu %llu\n", p, n);
	return 0;
}
ll gcd(ll a, ll b) {
	if(b==0)
		return a;
	return gcd(b, a%b);
}
ll unionCardinality() {
	int result=0;
	int size=4;
	int setSize=(1<<size);
	vector<int> indices;
	for(int b=1; b<setSize; ++b) {		
		for(int k=0; k<size; ++k)
			if(b&(1<<k))
				indices.push_back(k);
					
		int cardinality= intersectionCardinality(indices);
		
		if(indices.size()&1)
			result+=cardinality;
		else
			result-=cardinality;
		indices.clear();				
	}
	return result;
}
ll intersectionCardinality(vector<int>&indices) {	
	ll result=divisors[indices[0]];
	
	for(ll i=1; i<indices.size(); i++) {
		int index= indices[i];
		result=gcd(divisors[index], result);
	}
		
	result= n/result;
	return result;
}
