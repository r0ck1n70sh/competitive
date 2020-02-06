#include <bits/stdc++.h>
#define maxl (int)(1e5+7)
using namespace std;
void permute(int arr[maxl], int size, int l, int r){
	if(l==r) {
		for(int i=0; i<size; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}

	else {
		for(int i=l; i<=r; i++) {
			swap(arr[l], arr[i]);
			permute(arr, size, l+1, r);
			swap(arr[l], arr[i]);
		}
	}
}
int main(){
	int arr[]= {1,2,3};
	permute(arr, sizeof(arr)/sizeof(int), 0, sizeof(arr)/sizeof(int)-1);
	return 0;
}
