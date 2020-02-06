#include <bits/stdc++.h>
#define ll long long unsigned int
#define PSLL pair<string, ll>
#define maxl 100000+5
using namespace std;

bool comp(ll, ll);
vector<ll> arr;
map<string, ll> M;

int main() {
	int Q, K;
	ll E, spare=0;
	string S;
	scanf("%d%d", &Q, &K);
	
	for(int i=0; i<Q; i++){
		cin>>S>>E;
		if(M.find(S)==M.end())
			M.insert({S,E});
		else
			M.find(S)->second+=E;
	}
	
	for(auto it=M.begin(); it!=M.end(); it++)
		arr.push_back(it->second);
	
	sort(arr.begin(), arr.end(), comp);
	
	int count=0;
	for(auto it=arr.begin(); it!=arr.end(); it++) {
		if(count>=K)
			break;
		spare+=(*it);
		count++;
	}
	
	printf("%llu\n", spare);
	
	return 0;
}

bool comp(ll p1, ll p2) {
	return (p1 > p2);
}
