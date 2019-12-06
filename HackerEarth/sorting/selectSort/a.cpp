#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
using namespace std;
int main() {
	int n, x, min;
	int arr[101];
	scanf("%d%d",&n,&x);
	F(i,0,n)
		scanf("%d", arr+i);
		
	F(i,0,x) {
		min=i;
		F(j,i,n) {
			if(arr[min]>arr[j])
				min=j;
		}
		int temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
	
	F(i,0,n)
		printf("%d ", arr[i]);

	return 0;
}
