#include <bits/stdc++.h>
int rev(int);
int main(){
	int N, x1, x2;
	int res;
	scanf("%d", &N);
	while(N){
		scanf("%d%d", &x1, &x2);
		x1= rev(x1); x2=rev(x2);
		res= x1+x2;
		printf("%d\n", rev(res));
		N--;
	}	
	return 0;
}
int rev(int x){
	int res=0;
	while(x>0){
		res= res*10+x%10;
		x/=10;
	}
	return res;
}
