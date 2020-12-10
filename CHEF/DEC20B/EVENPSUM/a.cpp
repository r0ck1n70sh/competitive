#include <bits/stdc++.h>
#define ll long long unsigned
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		ll a, b, pairs;
		cin>>a>>b;
		
		pairs= (a/2)*(b/2) + (a-a/2)*(b-b/2);
		printf("%llu\n", pairs);	
	}

	return 0;
}

