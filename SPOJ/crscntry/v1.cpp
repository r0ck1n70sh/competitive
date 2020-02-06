#include <bits/stdc++.h>
#define maxl 2000+4
#define ll long unsigned int
using namespace std;

int lcs(vector<int>&, vector<int>&);
int main(){
	int d;
	scanf("%d", &d);
	while(d){
		vector<int> A, B;
		int x;
		scanf("%d", &x);
		while(x!=0){
			A.push_back(x);
			scanf("%d", &x);
		}
		
		int res=0;
		do{
			scanf("%d", &x);
			while(x!=0) {
				B.push_back(x);
				scanf("%d", &x);
			}
			res= max({res, lcs(A,B)});
			B.clear();
			scanf("%d", &x);
			B.push_back(x);
		}while(B[0]!=0);
		printf("%d\n", res);
				
		--d;
	}
	return 0;
}

int lcs(vector<int>&A, vector<int>&B){
	int m= A.size();
	int n= B.size();
		
	int dp[2][maxl]={0};
	int bi;
		
	for(int i=0; i<=m; i++) {
		bi= i&1;
		for(int j=0; j<=n; j++) {
			if(i==0 || j==0)
				dp[bi][j]=0;
			else if(A[i-1]==B[j-1])
				dp[bi][j]= dp[1-bi][j-1] +1;
			else
				dp[bi][j]= max(dp[1-bi][j], dp[bi][j-1]);
		}
	}	
	return dp[bi][n];
}
