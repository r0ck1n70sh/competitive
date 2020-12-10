#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int x, y; cin>>x>>y;
		
		int d = abs(x-y);
		if(d<=1){
			printf("%d\n", x+y);
			continue;
		}
		d-=1;
		printf("%d\n", 2*d + 2*min(x,y) + 1);
	}
	return 0;
}
