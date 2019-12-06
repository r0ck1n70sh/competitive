#include <bits/stdc++.h>
#define ull long long unsigned int
#define maxl 1000+1
#define mod(n) ((int)(n)%M)
#define F(i,a,b) for(int i=(int)a; i<(int)b; i++)
#define dp(N,X,D,f) dp[N][X][D][f] //D:Y-X+1	//f:{0,1}
ull dp[maxl][51][3][2];
ull M=1000000000+9;
int A[maxl];
int main() {
	int N, X, Y, ans;
	scanf("%d%d%d", &N, &X, &Y);
	F(i,1,N+1)
		scanf("%d",A+i);
		
	memset(dp,0,sizeof(dp));	//setting value
	 
	dp(1,0,1,0)=1; dp(1,0,1,1)=1; 
	F(i,2,N+1) {				//base case
		F(j,1,i) {
			if(A[j]<A[i])
				dp(i,0,1,1)=mod(dp(i,0,1,1)+1);
			else
				dp(i,0,1,0)=mod(dp(i,0,1,0)+1);
		}
	}
		
	F(i,3,N+1) {
		F(j,1,i) {
			if(A[j]<A[i]) {
				F(x,0,X+1) {
					if(x>i) break;
					F(y,0,3) {
						dp(i,x+1,y,1)=mod(dp(i,x+1,y,1)+dp(j,x,y,0));
						dp(i,x,y,1)=mod(dp(i,x,y,1)+dp(j,x,y,1));
					}
				}
			}
			else {
				F(x,0,X+1) {
					if(x>i) break;
					F(y,0,3) {
						dp(i,x,y,0)=mod(dp(i,x,y,0)+dp(j,x,y,0));
						if(y>1) continue;
						dp(i,x,y+1,0)=mod(dp(i,x,y+1,0)+dp(j,x,y,1));
					}
				}	
			}
		}
	}	
	
	F(i,2,N+1) {
		F(x,0,X+1) {
			if(x>i) break;
			F(y,0,3) {
				printf("%llu %llu: %d %d %d\n", dp(i,x,y,0), dp(i,x,y,1), i, x, y);
			}	
		}
	}
		
	ans=mod(dp(N,X,Y-X+1,0)+dp(N,X,Y-X+1,1));
	printf("%d\n",ans);
	return 0;
}
