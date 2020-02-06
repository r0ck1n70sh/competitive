#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int> mp;
int next(vector<int>&v){
	sort(v.begin(),v.end());
	
}
int main(){
	int x,q,m=0; scanf("%d%d",&q,&x);
	vector<int> v;
	for(int i=1,a;i<=q;i++){
		scanf("%d",&a); mp[a]++; v.push_back();
		if(abs(m-a)%x) {
			mp[m]++;
			if(m!=a) mp[a]--;
			m=next(v);
		}
		printf("%d\n",m);
	}
	return 0;
}
