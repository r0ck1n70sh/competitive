#include <bits/stdc++.h>
#define ll long long int
#define maxl (int)(1e6+1)
#define mod (ll)(1e9+7)
using namespace std;
int bcount(string&s){
	int count=0;
	for(int i=0; i<s.length(); i++)
		if(s[i]-'0')
			count++;
	return count;
}
ll binCoeff(int n, int r){
	ll C[r+1];
	memset(C,0,sizeof(C));
	C[0]=1;
	for(int i=1; i<=n; i++)
		for(int j=min(i,r); j>0; j--)
			C[j]=(C[j-1]+C[j])%mod;
	return C[r];
}
int main(){
	int t, n;
	string s1, s2;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		cin>>s1>>s2;
	
		int bit1=bcount(s1), bit2=bcount(s2);
		int _max= bit1+bit2-2*max({0, bit1+bit2-n});
		int _min= abs(bit1-bit2);
	
		ll res=0;
		for(int i=_min; i<=_max; i+=2)
			res=(res+binCoeff(n, i))%mod;
		printf("%lld\n", res);
	}

	return 0;
}
