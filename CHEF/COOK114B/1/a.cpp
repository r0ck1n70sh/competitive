#include <bits/stdc++.h>
using namespace std;
const int INF= 1e5+1;
int main(){
	int t; scanf("%d",&t);while(t--){
		int n, res=INF; scanf("%d",&n);
		for(int i=0,x;i<n;i++) {
			scanf("%d", &x); res=min(res,x);
		}
		printf("%d\n",res);
	}
}
