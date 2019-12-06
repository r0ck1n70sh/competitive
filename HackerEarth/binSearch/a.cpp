#include <bits/stdc++.h>
#define maxl 100001
using namespace std;
int arr[maxl];
int index(int,int,int);
int main() {
	int n, q, x;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	sort(arr, arr+n);
	scanf("%d", &q);
	while(q) {
		scanf("%d", &x);
		printf("%d\n", index(0,n,x)+1);
		--q;
	}
	return 0;
}
int index(int l, int h, int id) {
	int m=(h+l)/2;
	if(arr[m]==id)
		return m;
	
	if(arr[m]>id)
		return index(l,m,id);
		
	return index(m+1,h,id);	
}
