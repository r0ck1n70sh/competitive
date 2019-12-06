#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n, t;
	stack <int>sym;
	string str;
	scanf("%d", &t);
	
	for(int j=0; j<t; j++) {
		
		getline(cin, str);
		n=(int)str.length();
	
		for(int i=0; i<n; i++) {
			if(str[i]>96&&str[i]<123) 
				printf("%c", str[i]);
	
			else if((str[i]<48&&str[i]>41)||str[i]==94)
			    sym.push(str[i]);
		
			else if(str[i]==')') {
				printf("%c", sym.top());
				sym.pop();
			}
		}
		printf("\n");
	}

	return 0;
}
