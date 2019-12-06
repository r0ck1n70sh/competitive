#include <bits/stdc++.h>
int sngint(int n);
int main() {
	int n, t;
	scanf("%d", &t);
	for(int i=0; i<t; i++) {
		scanf("%d", &n);
		printf("%d\n", sngint(n));
	}			
	return 0;
}

int sngint(int n) {
	int ans=0, curVal=1, key;
	std::vector<int> factor, digits;
	if(n==0)
		return 10;
	if(n==1)
		return 1;
	
	for(int i=1; i<10; i++)
		if((n%i)==0)
			factor.push_back(i);
	if(factor.empty())
		return -1;
	
	for(auto i=factor.rbegin(); i!=factor.rend(); ) {
		key=(*i);
		if(curVal*key<=n) {
			curVal*=key;
			digits.push_back(key);
		}	
		else
			i++;
	}
	for(auto i=digits.rbegin(); i!=digits.rend(); i++) {
		key=(*i);
		ans*=10;
		ans+=key;
	}
	return ans;
}
