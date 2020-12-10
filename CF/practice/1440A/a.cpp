#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n, c0, c1, h;
		string s;
		cin>>n>>c0>>c1>>h;
		cin>>s;
		
		int z=0;
		for(int i=0; i<s.length(); i++)
			if(s[i] == '0')
				z++;

		int org = z*c0 + (n-z)*c1;
		int rz = h*z + n*c1;
		int ro = h*(n-z) + n*c0;
		printf("%d\n", min({org, rz, ro}));
	}
	
	return 0;
}
