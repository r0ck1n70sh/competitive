#include <bits/stdc++.h>
#define maxl 200000
using namespace std;
int main() {
	int sum=0;
	int N , K;
	int a[maxl];
	int diff[maxl];
	scanf("%d%d", &K, &N);
	for(int i=0; i<N; i++)
		scanf("%d", a+i);
	for(int i=0; i<N-1; i++) {
		diff[i]=abs(a[i]-a[i+1]);
		sum+=diff[i];
	}
	printf("%d ", sum);
	for(int i=1; i<N-1; i++) {
		int res= sum-diff[i-1]-diff[i]+abs(a[i+1]-a[i-1])+abs(a[i]-a[0]);
		printf("%d ", res);
	}
	int res= sum-diff[N-2]+abs(a[N-1]-a[0]);
	printf("%d", res);
	return 0;
}
