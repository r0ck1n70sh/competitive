#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
int main() {
	int n;
	int arr[101], index[101];
	scanf("%d", &n);	
	F(i,0,n) {
		scanf("%d", arr+i);
		index[arr[i]]=i;
	}
	F(i,0,n) {
		int temp=arr[i];
		int j=i;
		while(j>0&&temp<arr[j-1]) {
			arr[j]=arr[j-1];
			++index[arr[j-1]];
			--j;
		}
		arr[j]=temp;
		index[temp]=j;
		
	/*	F(i,0,n)
			printf("%d ", arr[i]);
		printf("\n");
		F(i,0,n)
			printf("%d ", index[i]+1);
		printf("|\n"); */
	}
	
	F(i,0,n)
		printf("%d ", index[arr[i]]+1);

	return 0;
}

