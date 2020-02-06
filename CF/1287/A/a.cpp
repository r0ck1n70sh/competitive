#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, n;
	string s;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		cin>>s;
		string pr;
		int m=-1;	
		do{
			pr=s;
			for(int i=0; i<n; i++) {
				if(s[i]=='A'){
					if(s[i+1]=='A')
						continue;
					s[i+1]='A';
					i++;
				}
			}
			m++;
		}while(pr!=s);
		printf("%d\n", m);
	}
}

