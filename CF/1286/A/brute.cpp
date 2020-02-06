#include <bits/stdc++.h>
#define INF (int)(1e8+1)
using namespace std;
int arr[110];
int n;
int solve(int idx, int even){
	//printf("{%d %d} ", idx, even);
	if(even<0)
		return INF;
	if(idx<=0){
		if(even!=0)
			return INF;
		return 0;
	}
	if(arr[idx]!=0){
		int res=0;
		if(arr[idx]&1){
			if(((arr[idx-1]&1)==0)&&(idx>1)&&arr[idx-1]!=0)
				res+=1;
			return solve(idx-1, even)+res;
		}
		if((arr[idx-1]&1)&&(idx>1)&&arr[idx-1]!=0)
			res+=1;
		return solve(idx-1, even-1)+res;
	}
	int res= solve(idx-1, even-1);
	if((arr[idx-1]&1)&&idx>1&&arr[idx-1]!=0)
		res+=1;
	int res1= solve(idx-1, even);
	if(((arr[idx-1]&1)==0)&&(idx>1)&&arr[idx-1]!=0)
		res1+=1;
	return min({res, res1});
}
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", arr+i);
	printf("%d\n", solve(n, n/2));
	return 0;
}
