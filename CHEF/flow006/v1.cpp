#include <bits/stdc++.h>
int main() {
	int t, n, d, sum;
	scanf("%d", &t);
	while(t) {
		sum=0;
		scanf("%d", &n);
		while(n) {
			d=(n%10);
			sum+=d;
			n/=10;
		}
		printf("%d\n", sum);
		--t;
	}
	return 0;
}
