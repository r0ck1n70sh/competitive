#include <bits/stdc++.h>
#define maxl (int)(2e3+7)
#define F(i,a,b) for(int i=(int)(a); i<=(int)(b); i++)
int arr[maxl][maxl]; int n;
bool check(){
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(arr[i][j]==0) return 0;
	for(int k=1;k<=2*n-1;k++)
		for(int idx=1;idx<=n;idx++) { int flag=1;
			for(int j=1;j<=n;j++) if(arr[idx][j]==k) flag=0;
			for(int j=1;j<=n;j++) if(arr[j][idx]==k) flag=0;
			if(flag) return 0;
	}
	return 1;
}
bool solve(int r, int c){
	printf("\n");for(int i=1;i<=n;i++){ 
		for(int j=1;j<=n;j++) printf("%d ", arr[i][j]);	printf("\n");
	}printf("\n");
	if(check()) return 1;if(r<=0) return solve(n,c-1);if(c<=0)return 0;
	for(int k=1;k<=2*n-1;k++){arr[r][c]=k;if(solve(r-1,c))return 1;}	
	return 0;
}
int main(){
	scanf("%d", &n); 
	if(solve(n,n)) {for(int i=1;i<=n;i++){ 
		for(int j=1;j<=n;j++) printf("%d ", arr[i][j]);	printf("\n");
	}}
}

