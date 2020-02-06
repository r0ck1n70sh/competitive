#include <bits/stdc++.h>
using namespace std;
bool vis[3];
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		memset(vis, 0, sizeof(vis));
		int S;
		int W[3];
		scanf("%d%d%d%d",&S,W,W+1,W+2);
		if(W[0]+W[1]+W[2]<=S)
			printf("1\n");
		else if((W[0]+W[1]<=S)||(W[1]+W[2]<=S))
			printf("2\n");
		else
			printf("3\n");
	}
	return 0;
}
