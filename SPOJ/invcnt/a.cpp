#include <bits/stdc++.h>
#define maxl 200000
#define ll long long unsigned int
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
int A[maxl];
ll invcnt(int, int);
ll merge(int, int, int);
using namespace std;
int main() {
	int t, n;
	ll ans;
	scanf("%d",&t);
	while(t) {
		scanf("%d", &n);
		F(i,0,n)
			scanf("%d", &A[i]);
		ans=invcnt(0,n-1);
		printf("%llu\n", ans);
		t--;
	}
	return 0;
}
ll invcnt(int start, int end) {
	int mid=(start+end)/2;
	return invcnt(start,mid)+invcnt(mid+1,end)+merge(start,mid,end);
}
ll merge(int start, int mid, int end) {
	int count=0;
	int p=start, q=mid, k=0;
	int arr[end-start+1];
	
	F(i,start,end+1) {
		if(p>mid)
			arr[k++]=A[q++];
		else if(q>end) {
			arr[k++]=A[p++];
			count++;
		}
		else if(A[p]<=A[q])
			arr[k++]=A[p++];
		else {
			arr[k++]=A[q++];
			count++;
		}
	}
	
	F(i,0,k)
		A[start++]=arr[i];
	return count;
}
