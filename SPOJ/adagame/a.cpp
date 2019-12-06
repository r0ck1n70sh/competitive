#include <bits/stdc++.h>
#define dp(i,j) dp[(int)(i)][(int)(j)]
using namespace std;
int dp[10001][101];	//
bool solve(string, int);
string ori;
int itr;
int main() {
	int T;
	string s;
	scanf("%d",&T);
	while(T) {
		memset(dp,-1,sizeof(dp));
		cin>>s>>itr;
		ori=s;
		if(solve(s,0))
			printf("Ada\n");
		else
			printf("Vinit\n");
		T--;
	}
	return 0;
}
bool solve(string s, int step) {
	if(step==itr) {
		if(s>ori) return 1;
		else return 0;
	}
	
	int z=stoi(s);
	string tm;
	bool ans;

	if(dp(z,step)!=-1)
		return dp(z,step);
	
	if(step&1)
		ans=true;
	else 
		ans=false;
		
	for(int i=0; i<4; i++) {
		tm=s;
		tm[i]=(tm[i]-'0'+1)%10+'0';
		
		if(step&1)
			ans&=solve(tm,step+1);
		else
			ans|=solve(tm,step+1);
	}
	return (dp(z,step)=ans);
}
