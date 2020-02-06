#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; cin>>t; string s;
	while(t--){
		cin>>s; ll n=ll(s.length()); ll res=0, tt=(n*(n+1))/2; 
		for(ll i=1;i<n;i++){
			if(s[i-1]!=s[i]) res+=n;
			else res+=(tt-n);
		}
		printf("%lld\n",res);
	}
	return 0;
}
