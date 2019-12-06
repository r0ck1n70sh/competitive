#include <bits/stdc++.h>
#define maxl 100001
using namespace std;
char str[maxl];
int countDistinct(int s, int e);
int main() {
	int Q;
	char q, x1, x2;
	scanf("%s", str);
	scanf("%d", &Q);
	while(Q) {
		scanf("\n%c %c %c", &q, &x1, &x2);
		if(q=='1') {
			int pos=x1-'1';
			str[pos]=x2;
		//	puts(str);
		//	printf("\n");
		}
		else {
			int l= x1-'1';
			int r= x2-'1';
			int m=countDistinct(l, r);
			printf("%d\n", m);
		}
		--Q;
	}
	return 0;
}
int countDistinct(int s, int e) {
	int count=0;
	bool vis[26];
	memset(vis, 0, sizeof vis);
	for(int i=s; i<=e; i++) {
		if(!(vis[str[i]-'a'])) {
			vis[str[i]-'a']=1;
			count++;
		}
	}
	return count;
}
