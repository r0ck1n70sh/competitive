#include <bits/stdc++.h>
int main() {
	int t, n, x;
	int score[200];
	scanf("%d", &t);
	while(t) {
		int m=0;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &x);
			score[i]=20*x;
		}
		for(int i=0; i<n; i++) {
			scanf("%d", &x);
			score[i]-=10*x;
			if(score[i]>m)
				m=score[i];
		}
		printf("%d\n", m);
		--t;
	}
	return 0;
}
