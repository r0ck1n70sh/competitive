#include <bits/stdc++.h>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;
typedef vector<vector<ll>> matrix;
matrix multiply(matrix a, matrix b){
	ll n=a.size();
	matrix c(n, vector<ll>(n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				c[i][j]+=(a[i][k]*b[k][j])%mod;
	return c;
}
matrix matpow(matrix m, int n){
	//printf("running %d\n", n);
	if(n==1)
		return m;
	if(n&1){
		matrix intm= matpow(m, n-1);
		return multiply(m, intm);
	}
	matrix intm= matpow(m, n/2);
	return multiply(intm, intm);
}
int main(){
	int n, d1, d2;
	scanf("%d%d%d", &n, &d1, &d2);
	matrix m={{3,4},{1,0}};
	if(n==1)
		printf("%d\n", d1);
	else if(n==2)
		printf("%d\n", d2);
	else{
		m=matpow(m, n-2);
		
		//for(int i=0; i<2; i++){
			//for(int j=0; j<2; j++)
				//printf("%lld ", m[i][j]);
			//printf("\n");
		//}
		
		ll res= ((d2*m[0][0])%mod+(d1*m[0][1])%mod)%mod;
		printf("%lld\n", res);
	}
	return 0;
}
