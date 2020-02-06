#include <bits/stdc++.h>
#define ll long long unsigned int
#define pii pair<ll, ll>
#define F first
#define S second
#define maxl (int)(1e5)+5
using namespace std;
int main(){
	int t, n;
	scanf("%d", &t);	
	while(t--){
		scanf("%d", &n);
		vector<pii> arr(n);
		for(int i=0; i<n; i++)
			scanf("%llu%llu", &arr[i].S, &arr[i].F);
		sort(arr.begin(), arr.end());
		int ans= INT_MAX;
		priority_queue<ll> pq;
		pq.push(arr[n-1].S);
		for(int i=n-2; i>=0; i--) {
			while(!pq.empty() && pq.top()>arr[i].F)
				pq.pop();
			if(n-i-pq.size()-1!=0)
				ans= min(ans, (int)pq.size());
			pq.push(arr[i].S);
		}
		if(ans==INT_MAX)
			ans=-1;
		printf("%d\n", ans);
	}
	return 0;
}
