#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, k, l;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &k, &l);
		if(n>k*l || (k==1 && n>1)){
			printf("-1\n");
			continue;
		}

		for(int i=1,cnt=0; cnt<n; i++,cnt++){
			if(i>k) i=1;
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
