#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		int n,k;cin>>n>>k;
		int p=n%k;
		if(p>k/2) {cout<<n-p+k/2<<"\n";continue;}
		//if(p>0)	{cout<<n-k+p<<"\n";continue;}
		else cout<<n<<"\n";
	}
}
