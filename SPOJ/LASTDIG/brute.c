#include <stdio.h>
int modexp(int a, int n){
	if(n==1) return a%10; if(n&1) return (a*modexp(a, n-1))%10;
	int res=modexp(a,n/2); return (res*res)%10;
}
int main(){
	int t,a,b; scanf("%d", &t);
	while(t--){
		if(b==0) {printf("1\n"); continue;}
		scanf("%d%d", &a, &b); printf("%d\n", modexp(a, b));
	} 
}
