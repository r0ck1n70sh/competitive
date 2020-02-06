#include <bits/stdc++.h>
using namespace std;
int dp[107][107];
int main(){
	string x, y; while(cin>>x){
		cin>>y ;
		int n=x.length(), m=y.length();
		memset(dp,0,sizeof(dp));
		for(int i=0; i<=n; i++){
			for(int j=0; j<=m; j++){
				if(i==0||j==0) continue;
				if (x[i-1]==y[j-1]) dp[i][j]=1+dp[i-1][j-1];
				else dp[i][j]= max({dp[i-1][j], dp[i][j-1]});
			}
		}
		int i=n+1, j=m+1; string res="";
		while(i>0 && j>0){
			if(x[i-1]==y[j-1]){ 
				res.push_back(x[i-1]); i--; j--;
			}
			else if(dp[i-1][j]>dp[i][j-1]) {res.push_back(x[i-1]); i--;}
			else {res.push_back(y[j-1]);j--;}
		}
		while(i>0){res.push_back(x[i-1]); i--;}
		while(j>0){res.push_back(y[j-1]); j--;}
		reverse(res.begin(), res.end());
		cout<<res<<"\n";
	}
	return 0;
}
