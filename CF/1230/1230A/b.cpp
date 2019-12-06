#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[4];
	for(int i=0;i<4;i++)
		scanf("%d",a+i);
	sort(a, a+4);
/*	for(int i=0; i<4; i++)
		printf("%d ", a[i]);
	printf("\n");	*/
	if((a[0]+a[3])==(a[1]+a[2]))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
