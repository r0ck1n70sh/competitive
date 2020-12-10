#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> v(n);
		for(int i=1; i<=n; i++)
			v[i-1] = n-i+1;
		
		if(n%2)
			swap(v[n/2], v.back());
		
		for(int i=0; i<n; i++)
			printf("%d ", v[i]);
		printf("\n");
	}
}
