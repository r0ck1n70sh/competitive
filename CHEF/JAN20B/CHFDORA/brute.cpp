#include <bits/stdc++.h>
#define maxl (int)(1e5+3)
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define A(i,j) arr[(int)(i)][(int)(j)]
using namespace std;
int n, m;
int pl(int x, int y, vector<vector<int>>&arr){
	int res=0;
	F(k,1,min({n,m})){
		if(x-k<0||x+k>n||y-k<0||y+k>m) break;
		if(A(x+k,y)!=A(x-k,y)||A(x,y+k)!=A(x,y-k)) break;
		res=k;
	}
	return res;
}
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int c=0;
		scanf("%d%d", &n, &m);
		vector<vector<int>> arr(n+3,vector<int>(m+3));
		F(i,0,n) F(j,0,m) scanf("%d", &arr[i][j]);
		c+=n*m;
		F(i,1,n) F(j,1,m) c+=pl(i,j,arr);
		printf("%d\n", c);arr.clear();
	}
	return 0;
}
