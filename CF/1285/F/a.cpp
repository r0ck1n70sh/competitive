#include <bits/stdc++.h>
#define maxl (int)(1e5+3)
using namespace std;
int arr[maxl], prime[maxl];
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}
int lcm(int a, int b){
	return (a*b)/gcd(a,b);
}
int genprime(int n){
	int res=(n&1?0:1);
	while(n%2==0) n/=2;
	for(int i=3; i<=sqrt(n); i+=2){
		if(n%i==0) res++;
		while(n%i==0) n/=i;
	}
	return res;	
}
int main(){
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++) {scanf("%d", arr+i); prime[i]=genprime(arr[i]);}
	int max=0, idx=0; sort(prime, prime+n);
	for(int i=0; i<n; i++) {
		if(prime[i]>=max) {max=prime[i]; idx=i;}
	}
	int res=0; for(int i=0; i<n; i++) {
		int curr=lcm(arr[idx], arr[i]); if(curr>res)res=curr;}
	printf("%d\n", res);
}
