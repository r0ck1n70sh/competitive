#include <bits/stdc++.h>
#define maxl 500
int res[maxl];
using namespace std;
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
	res[0]=1;
	int size=1;
	
	for(int x=2; x<=n; x++)
		size=multiply(x, size);
	for(int i=size-1; i>-1; i--)
		printf("%d", res[i]);
	printf("\n");
}
int multiply(int x, int size) {
	int carry=0, prod;
	for(int i=0; i<size; i++) {
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
