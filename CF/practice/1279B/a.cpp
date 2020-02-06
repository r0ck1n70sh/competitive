#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		int n,t;long long sum=0; cin>>n>>t; vector<int> x(n);
 		for(int i=0;i<n;i++) {cin>>x[i]; sum+=x[i];}
 		if(sum<=t){
			cout<<"0\n"; continue;
		}
		sum=0; int id=0;
		for(int i=0;i<n;i++){
			if(x[id]<x[i]) id=i;
			sum+=x[i];
			if(sum>t) break;
		}
		cout<<id+1<<"\n";
	}
}
