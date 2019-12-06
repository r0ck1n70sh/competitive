#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define maxl 20000
int A[maxl];
void msort(int, int);
void merge(int, int, int);
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	F(i,0,n)
		scanf("%d", A+i);
	msort(0, n-1);
	F(i,0,n)
		printf("%d ", A[i]);
	return 0;
}
void msort(int start, int end) {
	int mid=(start+end)/2;
	if(start<end) {
		msort(start, mid);
		msort(mid+1, end);
		merge(start, mid, end);
	}
}
void merge(int start, int mid, int end) {
	int n1=mid-start+1, n2=end-mid;
	int l[n1]; int r[n2];
	int p=0, q=0, k=start;
	
	F(i,0,n1)
		l[i]=A[start+i];
	F(i,0,n2)
		r[i]=A[mid+1+i];
	
	while(p<n1&&q<n2) {
		if(l[p]<=r[q]) {
			A[k]=l[p];
			p++;
		}
		else {
			A[k]=r[q];
			q++;
		}
		k++;
	}
	while(p<n1) {
		A[k]=l[p];
		p++; k++;
	}
	while(q<n2) {
		A[k]=r[q];
		q++; k++;
	}
}
