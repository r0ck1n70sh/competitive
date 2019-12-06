#include <stdio.h>
#include <stdlib.h>
int search(int arr[], int n , int key);
int main(){
	int n, i, key;
	int *arr;
	scanf("%d%d", &n, &key);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
		scanf("%d", arr+i);
	printf("%d\n", search(arr, n, key));
	return 0;
}

int search(int arr[], int n, int key) {
	int low=0, high=n-1;
	int mid;
	while(low<=high) {
		mid=(low+high)/2;
		if(arr[mid]<key)
			low=mid+1;
		else if(arr[mid]>key)
			high=mid-1;
		else
			return mid;
	//	printf("low:%d high:%d\n", low, high);
	}
	return -1;
}
