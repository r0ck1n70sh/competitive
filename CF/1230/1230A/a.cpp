#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[4];
	scanf("%d%d%d%d", a, a+1, a+2, a+3);
	int sum=a[0]+a[1]+a[2]+a[3];
	if(sum%1)
		printf("NO\n");
	else {
		int i;
		for(i=1; i<4; i++)
			if(sum/2==a[0]+a[i]) {
				printf("YES\n");
				break;
			}
		if(i>3)
			printf("NO\n");
	}
	return 0;
}
