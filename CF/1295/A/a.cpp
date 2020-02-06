#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t; while(t--){
		int n;cin>>n;
		int o=n/2, s=n%2;
		for(int i=0;i<s;i++) cout<<"7";
		for(int i=0;i<(s>0?(o-1):o);i++) cout<<"1";
		cout<<"\n";
	}
}

