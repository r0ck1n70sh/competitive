#include <bits/stdc++.h>
using namespace std;

int findLongestRepeatingSubSeq(string str){
	int n= str.length();
	
	int dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(str[i-1]==str[j-1] && i!=j)
				dp[i][j]= 1+ dp[i-1][j-1]
			else
				dp[i][j]= max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[n][n]		
}

int main(){
	string str;
	cin>>str;
	cout<<findLongestRepeatingSubSeq(str);
	return 0;	
}
