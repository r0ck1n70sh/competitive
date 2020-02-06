#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxl= 1e4+3;
int arr1[maxl], arr2[maxl];
unordered_map <int, int> s;
int main(){
	int n, m; scanf("%d",&n); while(n!=0){
		for(int i=0; i<n; i++) {scanf("%d", arr1+i); s.insert({arr1[i], i});}
		scanf("%d", &m); vector<pair<int, int>> v={{-1,-1}}; int sum=0;
		for(int i=0; i<m; i++){scanf("%d", arr2+i);
			if(s.count(arr2[i])){v.push_back({s[arr2[i]], i}); sum+=arr2[i];}
		} v.push_back({n,m});
		for(int i=1; i<v.size(); i++){
			int sum1=0, sum2=0;
			for(int k=v[i-1].F+1; k<v[i].F; k++) sum1+=arr1[k];
			for(int k=v[i-1].S+1; k<v[i].S; k++) sum2+=arr2[k];
			sum+=max({sum1, sum2});
		}
		printf("%d\n", sum); s.clear(); scanf("%d", &n);
	}
}
