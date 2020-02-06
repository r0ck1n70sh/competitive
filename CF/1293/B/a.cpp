#include <bits/stdc++.h>
using namespace std;
typedef double ld;
const int maxl=1e6+6;
int main(){
	ld n,sum=0; scanf("%lf",&n);
	for(int i=1;i<=n;i++) sum+=1.0/i;
	printf("%lf\n",sum);
	return 0;
}
