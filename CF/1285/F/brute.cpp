#include <bits/stdc++.h>
using namespace std;
int arr[100010]; const int INF=(1e9);
int main(){
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", arr+i);
	sort(arr, arr+n); int x=arr[n-1], idx=n-1, val=INF;
	for(int i=0; i<n-1; i++) {
		if(val>__gcd(x,arr[i])){val=__gcd(x,arr[i]); idx=i;}
	}
	int res= x*arr[idx]/val;
	printf("%d\n", res);
}
