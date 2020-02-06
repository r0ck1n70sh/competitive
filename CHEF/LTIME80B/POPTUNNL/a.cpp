#include <bits/stdc++.h>
#define S second
using namespace std;
const int inf=1e6;
typedef pair<int,int> PII;
vector<int> dp; int n,k;
vector<string> s;
int main(){
	int t; cin>>t; while(t--){
		cin>>n>>k;
		s=vector<string>(n);
		for(int i=0;i<n;i++) cin>>s[i]; 
		if(s[0][0]-'0'==0) {cout<<"-1\n"; continue;}
		dp=vector<int>(n, inf);
		dp[0]=0; 	
		priority_queue<PII,vector<PII>,greater<PII>> q;
		q.push({0,0}); vector<int> vis(n,0); 
		while(!q.empty()){
			PII node=q.top(); q.pop();
			if(vis[node.S]) continue;
			vis[node.S]=1;
			for(int i=node.S-1;i>=max(0,node.S-k);i--){
				if(s[node.S][i]-'0'==0) continue;
				if(dp[i]>dp[node.S]+1)
					dp[i]=dp[node.S]+1;//abs(node.S-i);
				q.push({dp[i],i});
			}
			for(int i=node.S+1;i<=min(n-1,node.S+k);i++){
				if(s[node.S][i]-'0'==0) continue;
				if(dp[i]>dp[node.S]+1)
					dp[i]=dp[node.S]+1;//abs(node.S-i);
				q.push({dp[i],i});
			}
		}
		int res=dp[n-1];
		if(res>inf-1) res=-1;
		cout<<res<<"\n"; dp.clear(); s.clear();
 	}
}
