#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int a,b,c,n; scanf("%d%d%d%d",&a,&b,&c,&n);
		int sum=(a+b+c+n), k=sum/3;
		if(sum%3==0&&k>=max({a,b,c})) printf("YES\n");
		else printf("NO\n");		
	}
	return 0;
}
