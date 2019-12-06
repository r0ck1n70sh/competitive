#include <bits/stdc++.h>
#define maxl 100000+5
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
int arr[maxl];
using namespace std;

int main() {
	int n, q;
	int x, y;
	scanf("%d", &n);
	F(i,1,n+1)
		scanf("%d", arr+i);
	scanf("%d", &q);
	while(q) {
		scanf("%d%d", &x, &y);
		if(arr[x+1]==0)
			printf("Odd\n");
		else if(arr[x]&1)
			printf("Odd\n");
		else
			printf("Even\n");
		--q;	
	}
	return 0;
}
