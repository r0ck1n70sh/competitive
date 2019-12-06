#include <stdio.h>
#define max 1000+1
#define F(i,a,b) for(i=(int)(a); i<(int)(b); i++)
int mat[max][max];
int main() {
	int N, M, Q;
	int i, j;
	scanf("%d%d", &N, &M);
	F(i,1,N+1)
		F(j,1,M+1)
			scanf("%d", &mat[i][j]);
	F(i,2,N+1)
		mat[i][1]+=mat[i-1][1];
	F(j,2,M+1)
		mat[1][j]+=mat[1][j-1];
		
	F(i,2,N+1)
		F(j,2,M+1)
			mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
	scanf("%d", &Q);
	while(Q) {
		scanf("%d%d",&i,&j);
		printf("%d\n", mat[i][j]);
		Q--;
	}
	return 0;
}
