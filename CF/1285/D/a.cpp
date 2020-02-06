#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[100010];
int setbit(int n){
	n|=n>>1; n|=n>>2; n|=n>>4; n|=n>>8; n|=n>>16; n+=1; return (n>>1);
}
int main(){
	int n, m=0; scanf("%d", &n);
	if(n==1) {int x; scanf("%d", &x); printf("%d", x); exit(0);}
	for(int i=0; i<n; i++){scanf("%d",arr+i); if(m<arr[i])m=arr[i];}
	int x=setbit(m)/2; m=0; 
	for(int i=0;i<n;i++) if(m<x^arr[i]) m=x^arr[i] ;
	printf("%d\n", m);
}
