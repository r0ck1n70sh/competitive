#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	
	set<int> s;
	for (int i=0,x; i<n; i++) {
		scanf("%d", &x);
		s.insert(x);
	}
	
	int res=0;
	for (auto x: s) {
		if (s.count(x+k)) res++;
	}
	
	printf("%d\n", res);
}
