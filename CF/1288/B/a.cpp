#include <bits/stdc++.h>
typedef long long ll;
const int maxl=1e6+3;
using namespace std;
int main(){
	int t; scanf("%d", &t);
	while(t--){
		ll res=0;int A, B, B1; scanf("%d%d", &A, &B); B1=B;
		while(B){res++; B/=10;}
		if(B1!=(int)pow(10, res)-(int)1) res--;
		//printf("%d\n", (int)pow(10, res+1));
		printf("%lld\n", res*A);
	}
	return 0;
}
