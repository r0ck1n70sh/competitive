#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main() {
	int t;
	char *str, *ch;
	stack<char> sym;
	scanf("%d", &t);
	
	while(t--) {
		str=(char*)malloc(sizeof(char)*400);
		ch=str;
		
		while(*str!=0) {		//input
			scanf("%c", str);
			str++;
		}
		
		while(*ch!=0) {		//logos
			if(*ch>96&&*ch<123) 
				printf("%c", *ch);
	
			else if(*ch>41&&*ch<48)
				sym.push(*ch);
		
			else if(*ch==')') {
				printf("%c", sym.top());
				sym.pop();
			}
			ch++;
		}
		printf("\n");
		free(str);
	}
	
	return 0;
}
