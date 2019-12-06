#include <bits/stdc++.h>
#define max 10000001
int main() {
	int t, n, curVal, key;	
	std::vector<int> factors, ans;
	scanf("%d", &t);
	while(t) {
		scanf("%d", &n);
		for(int i=2; i<10; i++)
			if((n%i)==0)
				factors.push_back(i);
		
		curVal=1;
		for(auto i=factors.rbegin(); i!=factors.rend(); ) {
			key=(*i);
			if(curVal*key<=n) {
				curVal*=key;
				ans.push_back(key);
			}
			else
				i++;
		}
	//	if(ans.empty())
	//		printf("True\n");
		if(factors.empty())
				printf("-1");
		else 
			for(auto i=ans.rbegin(); i!=ans.rend(); i++)
				std::cout<<(*i);

				
		printf("\n");		
		factors.clear();
		ans.clear();		
		t--;
	}	
	return 0;
}
