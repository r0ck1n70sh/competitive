#include <bits/stdc++.h>
using namespace std;
const int maxl=1e5+3;
int main(){
	int t;cin>>t;while(t--){
		int n;cin>>n;
		vector<int>m, arr(n,0), G(n+1,0), g(n+1,0), b(n,0);
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]!=-1) ++b[arr[i]];
			else m.push_back(i);
		}
		int sum=0, f=0;
		for(int i=0;i<=n;i++) {cin>>G[i]; sum+=(G[i]*i);}
		for(int i=0;i<=n;i++) ++g[b[i]];
		if(sum!=n||(G[0]==0&&G[1]!=n)) {printf("Impossible\n"); continue;}
		for(int i=n,j=0,k=0;i>0&&k<int(m.size());i--){
			if(g[i]==G[i]) continue;
			while(b[j]>=i) j++;
			while(g[i]!=G[i]){
				for(int p=0;p<i;p++,k++) arr[m[k]]=j;
				--g[b[j]]; b[j]=i;
				while(b[j]>=i) j++; 
				++g[i];
			}
		}
		if(f) {printf("Impossible\n"); continue;}
		for(int i=0;i<n;i++) printf("%d ",arr[i]);
		printf("\n");
	}
	return 0;
}
