#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	vector<int> v(n+2, 0);
	for (int i=1; i<=n; i++) scanf("%d", &v[i]);
	
	int count=0;
	for (int i=1; i<=n; i++) {		
		if (v[i-1]*v[i] == -1) {
			v[i-1]=0;
			v[i]=0;
		} else if (v[i]*v[i+1] == -1) {
			v[i]=0;
			v[i+1]=0;
			i++;
		} else {
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return 0;	
}
