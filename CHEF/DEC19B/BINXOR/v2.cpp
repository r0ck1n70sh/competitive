#include <bits/stdc++.h>
#define M (ll)(1e9+7)
#define maxl (ll)(1e5+5)
#define ll long long unsigned int
using namespace std;

ll C(int, int);
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
		ll result=0;
		if(n1+n2==N)
			result+=1;
		if(n1==n2)
			result+=1+C(N,n1)%M;
		else
			result= ((C(N,n1)%M)*(C(N,n2)%M))%M;
		printf("%lld\n", result);
		--T;
	}	
	return 0;
}

ll fact(ll N){
	if(dp[N]!=0)
		return dp[N];
	
	return dp[N]=((N%M)*(fact(N-1)%M))%M;
}

ll C(int N, int R){
	ll intm = ((fact(R)%M)*(fact(N-R)%M))%M;
	return (fact(N)/intm)%M;
}
