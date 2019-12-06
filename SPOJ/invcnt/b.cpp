#include <bits/stdc++.h>
#define maxl 200000
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define ll long long unsigned int
ll invcnt(int, int);
ll merge(int, int, int);
int A[maxl+1];
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int t, n; 
	ll ans;
	scanf("%d", &t);	//cin>>t;
	while(t) {
		scanf("%d", &n);		//cin>>n;
		F(i,0,n)
			scanf("%d",A+i);	//cin>>A[i];
		ans=invcnt(0,n-1);
		printf("%llu\n", ans);
		--t;
	}
	return 0;
}
ll merge(int start, int mid, int end) {
	ll count=0;
	int p=0, q=0, k=start;
	int n1=mid-start+1, n2=end-mid;
	int l[n1];	int r[n2];
	
	F(i,0,n1)
		l[i]=A[i+start];
	F(j,0,n2)
		r[j]=A[j+mid+1];
	
	while(p<n1&&q<n2) {
		if(l[p]>r[q]) {
			A[k]=r[q];
			q++;
			count+=n1-p;
		}
		else {
			A[k]=l[p];
			p++;
		}
		k++;
	}
	
	while(p<n1) {
		A[k]=l[p];
		k++; p++;
	}
	while(q<n2) {
		A[k]=r[q];
		k++; q++;
	}
	return count;
}
ll invcnt(int start, int end) {
	ll count;
	if(start<end) {
		int mid=(start+end)/2;
		
		count=invcnt(start,mid);
		count+=invcnt(mid+1,end);
		count+=merge(start,mid,end);
		return count;
	}
	return 0;
}
