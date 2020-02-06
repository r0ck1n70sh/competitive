// dp with recursion

#include <bits/stdc++.h>
#define maxl 2000+5
#define ll long long unsigned int
#define INF (ll)(-1)
using namespace std;

ll **dp;
ll V[26];
int N, M;
string A, B;
ll lcs(int, int);

int main() {
	scanf("%d%d", &N, &M);	
	for(int i=0; i<26; i++)
		scanf("%lld", V+i);	
	cin>>A>>B;
	
	dp=(ll**)calloc(N+1, sizeof(ll*));
	for(int i=0; i<N+1; i++)
		dp[i]= (ll*)calloc(M+1, sizeof(ll));
		
			
	printf("%lld\n", lcs(N, M));
	
/*	for(int i=0; i<N+1; i++) {
		for(int j=0; j<M+1; j++)
			printf("%lld ", dp[i][j]);
		printf("\n");
	}		
*/	
	return 0;
}

ll lcs(int n, int m) {
	if(n*m<=0)
		return 0;		
	
	if(dp[n][m]>0)
		return dp[n][m];
	
	if(A[n-1]==B[m-1])
		return dp[n][m]= max( {lcs(n-1, m), lcs(n, m-1), V[A[n-1]-'a']+lcs(n-1, m-1)} );

	return dp[n][m]= max( lcs(n-1, m), lcs(n, m-1));
}
