#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pt;
int lcm(int a, int b){
	return (a*b)/__gcd(a,b);
}
int main(){
	int t; cin>>t;
	while(t--){
		int n, p; cin>>n>>p;
		vector<int> res(n,0); vector<pt> r;
		for(int i=0,x;i<n;i++) {
			scanf("%d",&x); r.push_back({x,i});
		}
		sort(r.begin(),r.end());
		int curr=1, f=1;
		for(int i=0;i<n;i++){
			curr=lcm(curr, r[i].F);
			if(curr!=r[i].F){
				f=0; break; 
			}
			//cout<<curr<<" ";
		}
		if(f&&(p%curr==0)) {
			printf("NO\n"); continue;
		}
		int left=p, k=1;
		for(int i=n-1;i>=0;i--){
			if(r[i].F>left){
				res[r[i].S]=1; k=0;
				break;
			}
			int f=0;
			if(left%r[i].F==0) f=1;
			res[r[i].S]+=left/r[i].F;
			left=left%r[i].F;
			if(f){
				res[r[i].S]--; left+=r[i].F;
			}
			//cout<<left<<" ";
		}
		if(k) res[r[0].S]++;
		printf("YES ");
		for(int i=0;i<n;i++) printf("%d ",res[i]);
		printf("\n");
	}
}
