#include <bits/stdc++.h>
typedef long long ll;
const int maxl=1e6+3;
using namespace std;
int main(){
	int t; scanf("%d", &t);
	while(t--){
		ll d, n; scanf("%lld%lld", &n ,&d);
		if(d<=n) printf("YES\n");
		else{
			if(n&1){
				if(4*d<=n*n+1) printf("YES\n");
				else if(4*(d-n)<=(n-1)*(n-1)+1) printf("YES\n"); 
				else printf("NO\n");
			}
			else{
				if(4*d<=n*n) printf("YES\n");
				else if(4*(d-n)<=(n-1)*(n-1)) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}

