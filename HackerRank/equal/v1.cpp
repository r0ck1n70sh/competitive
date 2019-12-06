#include <bits/stdc++.h>
#define maxl 10005
#define ll unsigned
using namespace std;
ll pts[]={5,2,1};
ll arr[maxl];
ll numOps(ll);
int n;
int main() {
	int t;
	scanf("%d", &t);
	while(t) {
		ll sml=-1;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%u", arr+i);
			if(arr[i]<sml)
				sml=arr[i];
		}
		ll res=-1;
		for(int i=0; i<4 ;i++) {
			ll tmpAns=0;
			for(int j=0; j<n; j++)
				tmpAns+= numOps(arr[j]-sml+i);
				
			if(tmpAns<res)
				res=tmpAns;
		}
		printf("%d\n", res);
		--t;
	}
	return 0;
}
ll numOps(ll n) {
	int res=0;
	for(int i=0; i<3; i++) {
		res+=n/pts[i];
		n%=pts[i];
	}
	return res;
}
