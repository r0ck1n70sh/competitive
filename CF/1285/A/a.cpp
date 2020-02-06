#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, l=0, r=0; string s; cin>>n>>s;
	for(int i=0; i<s.length(); i++) {if(s[i]=='L')l++;else r++;}
	printf("%d\n", l+r+1);
}
