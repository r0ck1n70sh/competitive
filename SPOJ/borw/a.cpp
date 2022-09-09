#include <bits/stdc++.h>

using namespace std;

int dp(vector<int> &arr, int a, int d) {
	
}

int main () {
	while(true) {
		int n;		
		vector<int> arr;
		
		scanf("%d", &n);
		if (n < 0) break;
		
		if (n < 3) {
			printf("0\n");
			continue;
		}
		
		for(int i=0, x; i<n; i++) {
			scanf("%d", &x);
			arr.push_back(x);
		}
		
		printf("%d\n", min(
			dp(arr, arr[0], arr[1]),
			dp(arr, arr[1], arr[0]
		)));
	}
	
	return 0;
}
