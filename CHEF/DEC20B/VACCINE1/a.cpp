#include <bits/stdc++.h>
using namespace std;

int main(){
	int d1, d2, v1, v2, p;
	scanf("%d%d%d%d%d", &d1, &v1, &d2, &v2, &p);
	
	int days=0;
	while(p>0){
		days++;
		if(d1<=days)
			p-=v1;
		if(d2<=days)
			p-=v2;
	}
	printf("%d\n", days);	
}
