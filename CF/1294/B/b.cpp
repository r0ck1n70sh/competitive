#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pt;
const int maxl=1e3+4;
bool comp(pt a1, pt a2){
	if(a1.x!=a2.x) return a1.x<a2.x;
	return a1.y<a2.y;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,f=0; scanf("%d",&n); vector<pt> v;
		for(int i=0,p,q;i<n;i++){
			scanf("%d%d",&p,&q);v.push_back({p,q});
		}
		sort(v.begin(),v.end(),comp);
		for(int i=0;i<n-1;i++)
			if(v[i].y>v[i+1].y) {
				printf("NO\n"); f=1; break;
			}
		if(f) continue;
		printf("YES\n");
		pt curr={0,0};
		for(int i=0;i<n;i++) {
			for(int j=0;j<v[i].x-curr.x;j++) printf("R");
			for(int j=0;j<v[i].y-curr.y;j++) printf("U");
			curr=v[i];
		}
		printf("\n");
	}
	return 0;
}
