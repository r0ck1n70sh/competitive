#include <bits/stdc++.h>
char sign(int n);
int main() {
	int x, y, z;
	int res;
	scanf("%d%d%d", &x, &y, &z);
	res=x-y;
	
	if(abs(res)>z)
		printf("%c\n", sign(res));
	else if(z==0)
		printf("0\n");
	else
		printf("?\n");
	
	return 0;
}
char sign(int n) {
	if(n>0)
		return '+';
	else
		return '-';
}
