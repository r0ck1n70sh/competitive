#include <bits/stdc++.h>
using namespace std;
typedef long ll;
const int maxl= 1e5+10;
ll f[maxl]; int n;
void upd(int idx, ll val){
	for(;idx<=n+1;idx+=(idx&(-idx))) f[idx]+=val;
}
ll get(int idx){
	ll res=0; for(;idx>0;idx-=(idx&(-idx)))res+=f[idx]; return res;
}
ll singleGet(int idx){
	ll sum=f[idx];
	int z=idx-(idx&(-idx));
	--idx;
	while(idx!=z){
		sum-=f[idx]; idx-=(idx&(-idx));
	}
	return sum;	
}
bool check(ll sum){
	int lo=1, hi=n, mid;
	while(lo<=hi){
		mid=(lo+hi)/2; ll val=get(mid); 
		if(val==sum) return 1;
		if(val<sum) lo=mid+1;
		else hi=mid-1;
	}
	if(get(lo)==sum||get(hi)==sum) return 1;
	return 0;
}
int main(){
	scanf("%d", &n);
	for(int i=1,x;i<=n;i++) {scanf("%d",&x);upd(i,x);}
	int q;ll sum=get(n); scanf("%d",&q); while(q--){
		int c; scanf("%d",&c);
		if(c==1){
			int x; ll y; scanf("%d%ld",&x,&y);
			ll a=singleGet(x); upd(x,y-a); sum+=(y-a);
		}
		else{
			ll z; scanf("%ld",&z);
			if(check(sum-z)||sum==z) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
