#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
using namespace std;
void solve();
bool check(int);
int a[101][101];
int N, S, C;
int main() {
	int T;
	scanf("%d",&T);
	while(T) {
		memset(a,0,sizeof a);
		scanf("%d%d",&S,&C);
		N=S+C;
		F(i,0,S)
			scanf("%d", &a[i][0]);
		solve();
		F(i,S,N)
			printf("%d ", a[i][0]);
		printf("\n");
		T--;	
	}
	return 0;
}
void solve() {
	int k=0;
	while(!check(k)) {
		k++;
		F(j,0,S-k)
			a[j][k]=a[j+1][k-1]-a[j][k-1];
	}
	
	for(int i=k; i>-1; i--)	
			F(j,S-i,N)
				a[j][i]=a[j-1][i]+a[j-1][i+1];
}
bool check(int k) {
bool f=1;
	F(i,0,S-k)
		if(a[0][k]!=a[i][k]) {
			f=0;
			break;
		}
	
	return f;
}
