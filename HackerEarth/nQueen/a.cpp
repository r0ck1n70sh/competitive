#include <bits/stdc++.h>
#define F(i,N) for(int i=0; i<N; i++)
#define maxl 10
bool B[maxl][maxl];
bool solve(int);
bool attacked(int,int);
int N;
int main() {
	scanf("%d",&N);
	memset(B,0,sizeof B);
	if(solve(N)) {
		printf("YES\n");
	}
	else
		printf("No\n");
		
	F(i,N) {
		F(j,N)
			printf("%d ",B[i][j]);
		printf("\n");
	}	
	
	return 0;		
}
bool solve(int q) {
	if(q==0) return 1;
	
	F(i,N)
		F(j,N) {
			if(B[i][j]) continue;
			if(attacked(i,j)) continue;
			B[i][j]=1;
			if(solve(q-1)) return 1;
			B[i][j]=0;
	}
	return 0;	
}
bool attacked(int x, int y) {
	F(k,N) {
		if(B[k][y])
			return 1;
		if(B[x][k])
			return 1;
	}
	F(i,N)
		F(j,N) {
			if(i+j==x+y&&B[i][j])
				return 1;
			if(i-j==x-y&&B[i][j])
				return 1;
		}	
	return 0;
}
