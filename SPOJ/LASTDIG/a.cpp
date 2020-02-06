#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int a,b; scanf("%d%d", &a, &b); a=a%10; vector<int> arr;
		if(b==0) {printf("1\n"); continue;} 
		switch(a){
			case 0: break;
			case 1: break;
			case 2: arr={2,4,8,6}; a=arr[(b-1)%4]; break;
			case 3: arr={3,9,7,1}; a=arr[(b-1)%4]; break;
			case 4: if(b&1)a=4; else a=6; break;
			case 5: break;
			case 6: break;
			case 7: arr={7,9,3,1}; a=arr[(b-1)%4]; break;
			case 8: arr={8,4,2,6}; a=arr[(b-1)%4]; break;
			case 9: if(b&1)a=9; else a=1; break;
		}
		printf("%d\n", a);
	}
}
