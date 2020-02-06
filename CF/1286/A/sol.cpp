#include <bits/stdc++.h>
#define INF (int)(1e9)
#define maxl 110
using namespace std;
int arr[maxl];
int dp[maxl][maxl][2];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", arr+i);
	for(int i=0; i<=109; i++)
		for(int j=0; j<=109; j++){
			dp[i][j][0]=INF; dp[i][j][1]=INF;
		}			
	dp[0][0][0]=0; dp[0][0][1]=0;
	for(int idx=1; idx<=n; idx++){
		for(int e=0; e<=idx; e++){
			if(arr[idx]%2==1||arr[idx]==0)
				dp[idx][e][1]=min({dp[idx-1][e][1], dp[idx-1][e][0]+1});
			if(arr[idx]%2==0)
				dp[idx][e][0]=min({dp[idx-1][e-1][0], dp[idx-1][e-1][1]+1}); 
		}
	}
	printf("%d\n", min({dp[n][n/2][0],dp[n][n/2][1]}));
	return 0;
}
