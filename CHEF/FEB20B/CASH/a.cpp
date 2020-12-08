#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned llu;
int main(){
	int t; cin>>t;
	while(t--){
		int n ,k; scanf("%d%d",&n,&k);
		llu sum=0;
		for(int i=0,x;i<n;i++) {
			scanf("%d",&x); sum+=x;
		}
		printf("%llu\n",sum%k);
	}
	return 0;
}
