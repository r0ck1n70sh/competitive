#include <bits/stdc++.h>
using namespace std;
int n,k,i,x,o,h[10001];
int main() {
	memset(h,0,sizeof(h));
	scanf("%d%d",&n, &k);
	for(i=0;i<n;i++) {
		scanf("%d",&x);
		h[x]^=1;	//if odd make even, vice-versa
	}
	for(i=1;i<k+1;i++)
		if(h[i]==1)
			o++;
	printf("%d\n", n-o/2);	//o total odd students
	return 0;
}
