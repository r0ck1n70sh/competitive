#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, n;
	scanf("%d", &t);
	while(t){
		int x;
		int ans=0;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &x);
			ans+=x;
		}
		ans=ceil((float)ans/(float)n);
		printf("%d\n", ans);
		--t;
	}
	return 0;
}
