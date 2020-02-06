#include <bits/stdc++.h>
using namespace std;
typedef double dd;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		dd a,b,p,q;
		scanf("%lf%lf%lf%lf",&a,&b,&p,&q);
		//printf("%lf %lf %lf %lf:",a,b,p,q);
		if(a<b) swap(a,b);
		if(p<q) swap(p,q);
		if(a>=p&&b>=q) {printf("Escape is possible.\n"); continue;}
		if(b<q) {printf("Box cannot be dropped.\n"); continue;}
		dd lhs=(a+b)*(a+b)*(p-q)*(p-q);
		lhs+=(a-b)*(a-b)*(p+q)*(p+q);
		dd rhs=2*(p*p-q*q)*(p*p-q*q);
		//printf("%lf:",lhs-rhs);
		if(lhs-rhs>=0.000000) printf("Escape is possible.\n");
		else printf("Box cannot be dropped.\n");
	}
	return 0;
}
