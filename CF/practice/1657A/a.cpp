#include <bits/stdc++.h>

using namespace std;

bool is_integer(double n) {
	return n == floor(n);
}	

double distance(int x, int y) {
	return sqrt(x*x + y*y);
}

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int x, y;
		scanf("%d%d", &x, &y);
		
		int res;
		if(x==0 && y==0) {
			res=0;
		} else if (is_integer(distance(x, y))) {
			res=1;
		} else {
			res=2;
		}
		
		printf("%d\n", res);
	}
	
	return 0;
}
