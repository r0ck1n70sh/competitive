#include <bits/stdc++.h>
using namespace std;
int main(){
	int q,x; scanf("%d%d",&q,&x);
	vector <int> mods(x,0); set<pair<int,int>> vals;
	for(int i=0;i<x;i++) vals.insert({mods[i],i});
	for(int i=0;i<q;i++){
		int curr; scanf("%d",&curr); curr%=x;
		vals.erase({mods[curr],curr}); ++mods[curr];
		vals.insert({mods[curr],curr});
		curr=vals.begin()->first*x+vals.begin()->second;
		printf("%d\n",curr);
	}
	return 0;
}
