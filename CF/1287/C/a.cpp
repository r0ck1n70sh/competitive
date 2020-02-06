#include <bits/stdc++.h>
#define maxl 110
#define INF (int)(1e9+1)
using namespace std;
int arr[maxl];
int dp[maxl][maxl][2];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		scanf("%d", arr+i);
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++){
			arr[i][j][0]=INF; arr[i][j][1]=INF;
		}
	
	return 0;	
}
