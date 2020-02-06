#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxl=1e9+6;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n,s,k; scanf("%d%d%d",&n,&s,&k);
		unordered_set<int> c;
		for(int i=0,x;i<k;i++) {scanf("%d",&x);c.insert(x);}
		int res1=0, res2=0;
		for(;res1+s<=n;res1++) if(!c.count(s+res1)) break;
		for(;s-res2>0;res2++) if(!c.count(s-res2)) break;
		//printf("%d %d\n",res1, res2);
		if(res2==s) res2=maxl;
		if(res1+s>n) res1=maxl;
		printf("%d\n", min({res1, res2}));
	}
	return 0;
}
