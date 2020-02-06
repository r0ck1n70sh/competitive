#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		unordered_map<int,int> m;
		for(int i=0,x;i<n;i++) {
			scanf("%d",&x);
			if(m.count(x)) ++m[x];
			else m.insert({x,1});
		}
		int max1=0;
		for(auto it:m) if(it.second>max1) max1=it.second;
		printf("%d\n", n-max1);
	}
}
