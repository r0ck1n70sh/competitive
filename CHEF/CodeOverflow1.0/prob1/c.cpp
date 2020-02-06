#include <bits/stdc++.h>
#define mod (int)(1e5+7)
//#define maxl (int)(1e9+1)
using namespace std;
//ector<int> arr(maxl);
int main(){
	int d1, d2, n, res;
	scanf("%d%d%d", &n, &d1, &d2);
	if(n==1)
		printf("%d\n", d1);
	else if(n==2)
		printf("%d\n", d2);
	else{
		for(int i=3; i<=n; i++){
			res= (3*(d2%mod)+4*(d1%mod))%mod;
			d1=d2;
			d2=res;
		}
		printf("%d\n", res);
	}
}


