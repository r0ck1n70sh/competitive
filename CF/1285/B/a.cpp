#include <bits/stdc++.h>
#define maxl 100010
using namespace std;
int arr[maxl];
int main(){
	int t; scanf("%d", &t);
	while(t--){
		long long n, g=0, sum=0, f=0; scanf("%lld", &n);
		for(int i=1;i<=n;i++) {scanf("%d", arr+i); sum+=arr[i];};
		for(int i=2;i<n;i++) {g+=arr[i]; if(g<=0){g=0;f=1;}}
		if((g+arr[1]>=sum)||(g+arr[n]>=sum&&f)) printf("NO\n");
		else printf("YES\n");
	}
}
