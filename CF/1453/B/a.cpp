#include <bits/stdc++.h>
#define ll long long unsigned
using namespace std;

int main(){
	int t; cin>>t;
	
	while(t--){
		ll n; cin>>n;
		map<int, int> mp;
		
		int avg=0, maxfq=0, maxfx;
		for(ll i=0, x; i<n; i++){
			cin>>x;
			mp[x]++;
			avg+= x;
			if(mp[x]>maxfq) {
				maxfx = x;
				maxfq = mp[x];
			}
		}
		avg /= n;
		if(mp[avg]){
			mp[avg] += mp[maxfx];
			mp[maxfx] = 0;
		}
		
		ll mv=0;
		for(auto val : mp)
			mv += abs(val.first - avg) * val.second;
		
		printf("%llu\n", mv);
	}
	
	return 0;
}
