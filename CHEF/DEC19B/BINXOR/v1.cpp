//wrong logic

#include <bits/stdc++.h>
#define M (ll)(1e9+7)
#define mod(a) (ll)a%M
#define maxl (ll)(1e5+5)
#define ll long long unsigned int
using namespace std;

ll C(int, int);
ll modInverse(ll);
ll gcdExtended(ll, ll, ll*, ll*);
ll fact(ll);

ll dp[maxl]; 

int main(){
	int T, N;
	string A, B;
	scanf("%d", &T);
	memset(dp, 0 , sizeof(0));
	dp[0]=1;
	while(T){
		scanf("%d", &N);
		cin>>A>>B;
		int n1=0, n2=0;
		for(int i=0; i<A.length(); i++)
			if(A[i]=='1')
				++n1;
		for(int i=0; i<B.length(); i++)
			if(B[i]=='1')
				++n2;
		if(n1==n2)
			printf("%lld\n", C(N,n1));
		else
			printf("%lld\n", mod(mod(C(N,n1)) * mod(C(N,n2)) ) );
		--T;
	}
	return 0;
}

ll C(int N, int R){
	ll factN= fact(N);
	ll factR= fact(R);
	ll factNR= fact(N-R);
	
	ll inv= modInverse(mod(mod(factR)*mod(factNR)));
	return mod(mod(factN)*mod(inv));
}

ll modInverse(ll N){
	ll x, y;
	ll gcd= gcdExtended(N, M, &x, &y);
	
	return mod(mod(x)+M);
}

ll gcdExtended(ll a, ll b, ll*x, ll*y){
	if(a==0) {
		*x=0;
		*y=1;
		return b;
	}
	ll x1, y1;
	ll gcd= gcdExtended(b%a, a, &x1, &y1);
	
	*x= y1 - (b/a) * x1;
	*y= x1;
	
	return gcd;
}

ll fact(ll N){
	if(dp[N]!=0)
		return dp[N];
		
	return dp[N]=N*fact(N-1);
}
