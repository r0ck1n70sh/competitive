#include <stdio.h>
#define maxl 500
int res[maxl];
int multiply(int, int);
void factorial(int);
int main() {
	int t, n;
	scanf("%d",&t);
	while(t) {
		scanf("%d", &n);
		factorial(n);
		--t;
	}
	return 0;	
}
void factorial(int n) {
	int size=1, x, i;
	res[0]=1;
	
	for(x=2; x<=n; x++)
		size=multiply(x, size);
	for(i=size-1; i>-1; i--)
		printf("%d", res[i]);
	printf("\n");
}
int multiply(int x, int size) {
	int carry=0, prod, i;
	for(i=0; i<size; i++) {
		prod = res[i]*x +carry;
		res[i]=prod%10;
		carry=prod/10;
	}
	while(carry) {
		res[size]=carry%10;
		carry/=10;
		size++;
	}
	return size;	
}
