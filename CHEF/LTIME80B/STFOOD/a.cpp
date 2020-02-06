#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		int n;cin>>n;
		vector<int>p(n),s(n),v(n);
		for(int i=0;i<n;i++)
			cin>>s[i]>>p[i]>>v[i];
		int ans=0;
		for(int i=0;i<n;i++)
			ans=max(ans,v[i]*(p[i]/(s[i]+1)));
		printf("%d\n",ans);
	}
}
