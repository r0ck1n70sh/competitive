#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll x0,y0,ax,ay,bx,by,xs,ys,t;
	scanf("%lld%lld%lld%lld%lld%lld",&x0,&y0,&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&xs,&ys,&t);
	vector<ll> x(1,x0), y(1,y0);
	ll LIMIT=(1LL<<62)-1;
	while((LIMIT-bx)/ax>=x.back()&&(LIMIT-by)/ay>=y.back()){
		x.push_back(ax*x.back()+bx); y.push_back(ay*y.back()+by);
	}
	int n=int(x.size()), ans=0;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			ll length=x[j]-x[i]+y[j]-y[i];
			ll dist2Left= abs(xs-x[i])+abs(ys-y[i]);
			ll dist2Right=abs(xs-x[j])+abs(ys-y[j]);
			if(length<=t-dist2Left||length<=t-dist2Right)
				ans=max(ans,j-i+1);
		}
	printf("%d\n",ans);
}
