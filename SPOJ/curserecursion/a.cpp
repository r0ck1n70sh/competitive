#include <bits/stdc++.h>
int posNK(int, int);
int main() {
	int N, K, T;
	scanf("%d",&T);
	while(T) {
		scanf("%d%d",&N, &K);
		if(K>((1<<N)-1)) {
			printf("0\n");
			T--;
			continue;
		}
		printf("%d\n", posNK(N,K));
		T--;
	}
	return 0;
}
int posNK(int n, int k){
	if(k==(1<<(n-1)))
		return n;
	if(k>(1<<(n-1)))
		k-=(1<<(n-1));		
	return posNK(n-1, k);
}
