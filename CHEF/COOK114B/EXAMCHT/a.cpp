#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; scanf("%d",&t);while(t--){
		int a,b; scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		int p=(b-a), f=0; 
		for(int i=1;i*i<=p;i++){
			if(!(p%i)){
				if(i*i==p) f+=1;
				else f+=2;
			}
		}
		printf("%d\n",f);
	}
	return 0;
}
