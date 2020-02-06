#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxl=1e5+3;
bool arr[2][maxl];
int main(){
	memset(arr,0,sizeof(arr));
	int n,q,c=0; scanf("%d%d",&n,&q);
	for(int i=0;i<q;i++){
		int x,y; scanf("%d%d",&x,&y); --x;
		if(arr[x][y]) arr[x][y]=0; //printf("%d ", arr[x][y]);
		else arr[x][y]=1;
		if(arr[x][y]){
			if(arr[!x][y]) c++;
			if(y<=n) if(arr[!x][y+1]) c++;
			if(y>0) if(arr[!x][y-1]) c++;
		}
		else{
			if(arr[!x][y]) c--;
			if(y<=n) if(arr[!x][y+1]) c--;
			if(y>0) if(arr[!x][y-1]) c--;
		}
		if(c) printf("No\n");
		else printf("Yes\n");
		//for(int i=0;i<n;i++)
			//printf("{%d %d} ",arr[0][i],arr[1][i]);
		//printf("\n");
	}
	return 0;
}
