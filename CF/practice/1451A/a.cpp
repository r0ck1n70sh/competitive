#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		
		if(n==1){
			printf("0\n");
			continue;
		}
		if(n==2){
			printf("1\n");
			continue;
		}
		if(n==3){
			printf("2\n");
			continue;
		}
		
		if(n%2)
			printf("3\n");
		else
			printf("2\n");		
	}
}
