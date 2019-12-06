#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
using namespace std;
int main() {
	bool f;
	int n, swap=0;
	int arr[101];
	scanf("%d", &n);
	F(i,0,n)
		scanf("%d", arr+i);
	
	F(k,0,n-1) {
		f=1;
		F(i,0,n-k-1) {
			if(arr[i]>arr[i+1]) {
				swap++; f=0;
				int temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
		if(f)
			break;
	}
	
//	F(i,0,n)
//		printf("%d ",arr[i]);
	printf("%d", swap);
	return 0;
}
