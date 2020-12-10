#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n, m; 
		cin>>n>>m;
		map<int, int> mp;
		for(int i=0, x; i<n; i++){
			cin>>x;
			mp[x]++;
		}
		
		int cnt=0;
		for(int i=0, x; i<m; i++){
			cin>>x;
			if(mp[x]) cnt++;
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}
