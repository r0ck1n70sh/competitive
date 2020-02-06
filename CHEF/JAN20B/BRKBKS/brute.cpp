#include <bits/stdc++.h>
using namespace std;
bool vis[3];
int turn(int S, int W[3], int l, int r){
	if(l>r)
		return 0;
	int fr=1, bk=1;
	bool flag=0;
	int sum=0, idx=l;
	for(int i=l; i<=r; i++){
		sum+=W[i];
		if(sum>S){
			flag=1;
			idx=i;
			break;
		}
	}
	if(!flag)
		idx=r+1;
	fr+=turn(S,W,idx,r);
	//printf("fr(%d,%d):%d\n",idx,r,fr);
	sum=0, idx=r, flag=0;
	for(int i=r; i>=l; i--){
		sum+=W[i];
		if(sum>S){
			flag=1;
			idx=i;
			break;
		}
	}
	if(!flag)
		idx=l-1;
	bk+=turn(S,W,l,idx);
	//printf("bk(%d,%d):%d\n",l,idx,bk);
	return min({bk, fr});
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		memset(vis, 0, sizeof(vis));
		int S;
		int W[3];
		scanf("%d", &S);
		for(int i=0; i<3; i++)
			scanf("%d", W+i);
		printf("%d\n", turn(S, W, 0, 2));
	}
	return 0;
}
