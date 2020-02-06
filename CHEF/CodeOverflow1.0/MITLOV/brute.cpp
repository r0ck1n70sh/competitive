#include <bits/stdc++.h>
#define maxl (int)(1e9+1)
using namespace std;
int main(){
	int a, b;
	scanf("%d%d", &a,  &b);
	int k=max(a,b);
	while(k%a!=0||k%b!=0){
		k++;
		if(k>maxl)
			break;
	}
	printf("%d\n", k);
	return 0;
}
