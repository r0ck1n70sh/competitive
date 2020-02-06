#include <bits/stdc++.h>
#define maxl (int)(1e6+1)
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int res=1;
	for(int i=2; i<=n; i++){
		res+=4*(i-1)+1;
	}
	printf("%d\n",res);
}
