#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		int a,b,c; cin>>a>>b>>c;
		int m=max({a,b,c});
		if(m-1>(a+b+c-m)) printf("No\n");
		else printf("Yes\n");
	}
}
