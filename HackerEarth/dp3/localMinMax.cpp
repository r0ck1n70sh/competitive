#include <bits/stdc++.h>
#define max 1000+1
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define dp(n,i,j,k) dp[(int)n][(int)i][(int)j][(int)k]
int dp[max][51][3][2]; //dp[N][X][Y-X][{0,1}]
int A[max];
void build(int, int);
int main(){
	int N, X, Y;
	int ans;
	scanf("%d%d%d", &N, &X, &Y);
	F(i,1,N+1)
		scanf("%d", A+i);
	
	build(N,X);
	ans=dp(N,X,Y-X+1,0)+dp(N,X,Y-X+1,1);
	F(n,0,N+1)
		F(x,0,X+1)
			F(y,0,3)
				printf("%d %d:%d %d %d\n", dp(n,x,y,0), dp(n,x,y,1), n, x, y);
	printf("%d\n",ans);	
	return 0;
} 
void build(int N, int X){
	memset(dp, 0, sizeof(dp));
	//base case;
	if(A[1]<A[2])	// "/" : Maxima
		dp(2,0,2,1)=1;
	else   			// "\" : Minima
		dp(2,1,0,0)=1;
	
	F(i,3,N+1) {
		F(j,1,i) {
			if(A[j]<A[i]) {	// "/" : (1)
				F(x,0,X+1) {
					if(x>i) continue;
					F(y,0,3) {
						dp(i,x,y,1)+=dp(j,x,y,1);
						dp(i,x+1,y,1)+=dp(j,x,y,0);
					}
				}
			}
			else {	// "\"	: (0)
				F(x,0,X+1) {
					if(x>i) continue;
					F(y,0,3) {
						dp(i,x,y,0)+=dp(j,x,y,0);
						if(y>1) continue;
						dp(i,x,y+1,0)+=dp(j,x,y,1);
					}
				}
			}
		}
	}
}
