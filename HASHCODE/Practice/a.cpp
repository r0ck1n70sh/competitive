#include <bits/stdc++.h>
using namespace std;
const int maxl=1e5+3;
int arr[maxl], dp[maxl];
int m, n;
void dp_approach(){
	for(int i=1;i<m;i++){
		for(int j=1;j<i;j++)
	}
}
void greedy_approach(){
	int i=n-1;
	vector<int> res;
	while(i>=0){
		if(m-arr[i]>=0) {
			m-=arr[i]; res.push_back(i);
		}
		if(m<arr[0]) break;
		i--;
	}
	printf("%d\n", int(res.size()));
	for(int i=res.size()-1;i>=0;i--) printf("%d ", res[i]);
	printf("\n");
}
int main(){
	freopen("in/a.txt", "r",stdin);
	freopen("out/a.txt","w",stdout);
	cin>>m>>n;
	for(int i=0;i<n;i++) scanf("%d", arr+i);
	if(m<=1e3+1) dp_approach();
	else greedy_approach();
	return 0;
}
