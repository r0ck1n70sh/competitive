#include <bits/stdc++.h>
#define PII pair<int,int>
#define maxl 8
using namespace std;

int findLongestRepeatingSubSeq(string str){
	const int n= maxl;
		
	array< array<PII, n+1 >, n+1 > dp;
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			dp[i][j]= make_pair(0,0);
//	memset(dp, 0, sizeof(dp));
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			int k= dp[i-1][j-1].first;			
			int m= dp[i-1][j-1].second;
						
			if(str[i-1]==str[j-1] && i!=j) {
				dp[i][j].first= 1+k;
				dp[i][j].second= m;
			}
				
			else if(str[i-1]==str[j-1] && i==j && m+1<k) {
					dp[i][j].first= 1+ k;
					dp[i][j].second= 1+ m; 
			}			
			else {
				k= max(dp[i][j-1].first, dp[i-1][j].first);
				if(dp[i][j-1].first>dp[i-1][j].first)
					m=dp[i][j-1].second;
				else
					m=dp[i-1][j].second;
				dp[i][j].first=k;
				dp[i][j].second=m;
			}
		}dp[i-1][j-1].second
	}
	printf("%d\n",dp[n][n].second);
	return dp[n][n].first;	
}

int main(){
	string str;
	cin>>str;
	cout<<findLongestRepeatingSubSeq(str);
	return 0;	
}
