#include <bits/stdc++.h>
using namespace std;
int dr[1000];
bool great(int, int);
int main(){
	int n, k, x, totalDr, maxChild=0;
	scanf("%d%d", &n, &k);
	memset(dr, 0, sizeof(x));
	for(int i=0; i<n; i++) {
		scanf("%d", &x);
		++dr[x-1];
	}
	if(n%2==1)
		totalDr=n+1;
	else
		totalDr=n;
	sort(dr, dr+k, greater<int>());
	x=0;
	while(totalDr>0&&x<k) {
		maxChild+=min(dr[x],totalDr);
		if(dr[x]%2==1)
			++dr[x];
		totalDr-=dr[x];
		x++;
	}
	printf("%d\n", maxChild);
	return 0;
}
bool great(int a1, int a2) {
	return (a1>a2);
}
