#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define maxl 1000000
using namespace std;
int arr[maxl];
int n;
void qSort(int, int);
int partition(int, int);
int randPartition(int, int);
int main() {
	scanf("%d", &n);
	F(i,0,n)
		scanf("%d", arr+i);
	qSort(0,n-1);
	F(i,0,n)
		printf("%d ", arr[i]);
	return 0;
}
void qSort(int s, int e) {
	if(s<e) {
		int piv=randPartition(s, e);
		qSort(s,piv-1);
		qSort(piv+1,e);
	}
}
int randPartition(int s, int e) {
	int random= s+ rand()%(e-s+1);
	swap(arr[random], arr[s]);
	return partition(s, e);
}
int partition(int s, int e) {
	int i=s+1;
	int piv=arr[s];
		
	F(j,s+1,e+1) {
		if(arr[j]<piv) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[s], arr[i-1]);
	return i-1;
} 
