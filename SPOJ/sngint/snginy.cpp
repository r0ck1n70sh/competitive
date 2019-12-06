#include <bits/stdc++.h>
int main() {
	int t, n;
	std::vector<int> factors;
	scanf("%d", &t);
	while(t) {
		scanf("%d", &n);
		for(int i=1; i*i<n; i++) {
			if((n%i)==0) {
				factors.push_back(i);
				factors.push_back(n/i);
			}
		}
		std::sort(factors.begin(), factors.end());
		for(std::vector<int>::iterator i=factors.begin(); i!=factors.end(); i++)
			std::cout<<*i<<" ";
		printf("\n");
		factors.clear();
		
		t--;
	}	
	return 0;
}
