#include <bits/stdc++.h>
#define ll long double
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define dp(i,j) dp[i][j]
#define maxl 545
void solve(int, int);
ll dp[maxl*6][maxl];
//ll INF=-1;
using namespace std;
int main() {
	int T, sum, turn;
	double res;
	scanf("%d",&T);
	//memset(dp, 0, sizeof(dp));
	while(T) {
		scanf("%d%d", &turn, &sum);
		if(turn>545||sum>1908) {
			printf("0\n");
			return 0;
		}		
		solve(sum, turn);
		res=dp(sum, turn);
		cout<<floor(res*100)<<endl;
		T--;
	}
	return 0;
}
void solve(int sum, int turn) {
	if(dp(sum,turn)>0)
		return;
	
	F(i,1,7)
		dp(i,1)=1.0/6.0;
	
	F(n,2,turn+1)
		F(s,n,n*6+1) {
			F(k,1,7) {
				if(s-k<0)
					break;
				dp(s,n)+=dp(s-k,n-1);
				dp(s,n)/=6.0;
			}
		}
}
