#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, n, res;
	string str;
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n);
		cin>>str;
		
		res=0;
		for(int i=0; i<n-1; i++) {
			if (str[i]=='1') continue;
			
			for(int j=i+1; j<min(i+4, n); j++) {
				if (str[j]=='1') continue;
				
				int diff=j-i;
				switch(diff) {
					case 1:
						res+=2;
						break;
					case 2:
						res+=1;
						break;
					default:
						break;
				}
				
				break;
			}
		}
		
		printf("%d\n", res);
	}

	return 0;
}

