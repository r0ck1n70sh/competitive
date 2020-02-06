#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<int>> a(n,vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]); --a[i][j];
		}
	long long ans=0;
	for(int j=0;j<m;j++){
		vector<int> cnt(n,0);
		for(int i=0;i<n;i++)
			if(a[i][j]%m==j){
				int pos=(a[i][j]-j)/m;
				if(pos<n) ++cnt[(i-pos+n)%n];
			}
		int curr=n-cnt[0];
		for(int i=1;i<n;i++) curr=min(curr,n-cnt[i]+i);
		ans+=curr;
	}
	printf("%lld\n",ans);
	return 0;		
}
