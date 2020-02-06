//dp approach

#include <bits/stdc++.h>
#define maxl (int)(1e5+5)
using namespace std;

int dp[maxl];
int main(){
	int T, N;
	string S;
	scanf("%d", &T);
	
	while(T) {
		memset(dp, 0, sizeof(dp));
		scanf("%d", &N);
		cin>>S;
		
		for(int i=1; i<N; i++){
			for(int j=0; j<i; j++) {
				if(S[j]==S[i])
					dp[i]= max(j+1, dp[i]);
				dp[i]= max(dp[j], dp[i]);
			}
		}
		
		printf("%d\n", dp[N-1]);		
		--T;
	}
	return 0;
}
