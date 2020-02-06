#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const int maxl=2e5+3, INF=1e9;
ll diff[maxl]; int arr[maxl];
unordered_map<ll,int> m1, m2;
int main(){
	int t;scanf("%d",&t);while(t--){
		int n; scanf("%d",&n); ll sum=0, res=0, ss=0;
		for(int i=0;i<n;i++) {scanf("%d",&arr[i]);sum+=arr[i];}
		for(int i=0;i<n;i++){ss+=arr[i]; diff[i]=ss-(sum-ss);}
		for(int i=0;i<n-1;i++) {
			if(abs(diff[i])>INF) continue;
			m1[diff[i]]++;
		}
		for(int i=0;i<n;i++){
			res+=m1[arr[i]];res+=m2[-1*arr[i]];
			if(abs(diff[i])>INF) continue;
			m1[diff[i]]--; m2[diff[i]]++; 
		}
		printf("%lld\n",res);
		m1.clear();m2.clear();
	}
	return 0;
}
