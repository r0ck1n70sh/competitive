#include <bits/stdc++.h>
using namespace std;

int bin2int(string);
int main(){
	int T;
	string A, B;
	scanf("%d", &T);
	
	while(T){
		cin>>A>>B;
		int x, y;
		x= bin2int(A);
		y= bin2int(B);
		int count=0;
		
		while(y!=0){
			count++;
			int u= x^y;
			int v= x&y;
			x=u;
			y=v<<1;
		}
		printf("%d\n", count);
		--T;
	}
	return 0;
}

int bin2int(string s) {
	reverse(s.begin(), s.end());
	int res=0;
	for(int i=0; i<s.length(); i++) {
		res+= (s[i]-'0')*(1<<i);
	}
	return res;
}
