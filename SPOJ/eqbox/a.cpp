#include <bits/stdc++.h>
#define sq(a) (ll)(a)*(ll)(a)
#define ll long long int
#define dd double
typedef long long i64;
using namespace std;
bool eq(dd a, dd b, dd x, dd y){
	dd D=sqrt(x*x+ y*y- b*b);
	dd RHS= 2.0*x*y*b+ (2.0*y*y+x*x)*D;
	RHS/=(x*x+y*y);
	dd LHS=a;
	//printf("%f %f\n", LHS, RHS);
	//printf("%f\n", LHS-RHS);
	return (LHS-RHS>0.0000001);
}
//bool eq(ll a, ll b, ll x, ll y) {
	//ll S= x*x+y*y;
	//ll D= (ll)sqrt(x*x+y*y-b*b);
	//ll LHS= a*S;
	//ll RHS= 2*x*y*b+ y*y*D+ S*D;
	//return LHS>RHS;
//}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll A,B,X,Y;
		scanf("%lld%lld%lld%lld", &A, &B, &X, &Y);
		if(B>A)	swap(A,B);
		if(Y>X)	swap(X,Y);
		
		if(A>=X&&B>=Y) {
			printf("Escape is possible.\n");
			continue;
		}
		//if(A*A+B*B>=X*X+Y*Y)
		if(eq(A,B,X,Y)&&(A*B>=X*Y))
			printf("Escape is possible.\n");
		else
			printf("Box cannot be dropped.\n");
	}
	return 0;
}

//int main(){
	//ll A, B;
	//scanf("%lld%lld", &A, &B);
	//printf("%lld %lld\n", sq(A), sq(B));
	//return 0;
//}
