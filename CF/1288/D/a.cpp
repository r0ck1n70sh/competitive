#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pt;
typedef long long ll;
const int maxl=3e5+3, INF=1e9+1;
int arr[maxl][9];
vector<int> v[maxl][9];
int main(){
	int n, m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) scanf("%d", &arr[i][j]); //printf("run\n");
	for(int j=1;j<=m;j++) {
		multimap<int,int> m; vector<int> k;
		for(int i=1;i<=n;i++) m.insert({arr[i][j], i});
		for(auto &i:m) k.push_back(i.S); int p1=n-1, p2=n-1;
		while(p2>=0){
			if(arr[k[p2]][j]!=arr[k[p1]][j]) {k.pop_back(); p1=p2;}
			copy(k.begin(),k.begin()+p1+1,back_inserter(v[k[p2]][j]));
			p2--;
		}
	} //printf("run\n");
	//for(int i=1;i<=n;i++)
		//for(int j=1;j<=m;j++){
			//printf("{%d %d}: ",i,j);
			//for(int k=0;k<v[i][j].size();k++) printf("%d ", v[i][j][k]);
			//printf("\n");
		//}
	vector<pair<int, pt>> ans;
	for(int i=1;i<=n;i++){
		int imd=INF, imdj=0;
		for(int j=1;j<=m;j++) if(imd>arr[i][j]) imd=arr[i][j], imdj=i;
		for(int j=1;j<=m;j++)
			if(arr[i][j]==arr[i][imdj])
				ans.push_back({arr[i][j],{i,j}});
	}
	sort(ans.begin(),ans.end(),greater<pair<int,pt>>());
	printf("%d %d\n", ans[0].S.F, v[ans[0].S.F][ans[0].S.S][0]);
	return 0;
}
