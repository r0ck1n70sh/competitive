#include <bits/stdc++.h>
using namespace std;
int a1,a2,n,m;
vector<vector<int>> arr;
bool check(int x){
	vector<int> msk((1<<m),-1);
	for(int i=1;i<=n;i++){
		int curr=0;
		for(int j=1;j<=m;j++)
			if(arr[i][j]>=x) curr^=(1<<(j-1));
		msk[curr]=i;
	}
	if(msk[(1<<m)-1]!=-1){
		a1=a2=msk[(1<<m)-1]; return 1;
	}
	for(int b1=0;b1<(1<<m);b1++){
		if(msk[b1]==-1) continue;
		for(int b2=0;b2<(1<<m);b2++){
			if(msk[b2]==-1) continue;
			if((b1|b2)==(1<<m)-1){
				a1=msk[b1]; a2=msk[b2]; return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	arr.resize(n+3, vector<int>(m+3));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d", &arr[i][j]);
	int l=0, r=100;
	while(r-l>1){
		int m=(l+r)/2;
		if(check(m)) l=m;
		else r=m;
	}
	assert(check(l));
	printf("%d %d\n", a1, a2);
	return 0;
}
