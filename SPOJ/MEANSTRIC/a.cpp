#include <bits/stdc++.h>
using namespace std;
typedef double dd;
int main(){
	int t; cin>>t;
	while(t--){
		dd n; cin>>n;
		dd sum=0, isum=0, pr=1; 
		for(int i=0;i<int(n);i++) {
			dd x; cin>>x;
			sum+=x; isum+=1/x; pr*=x;
		}
		printf("%lf %lf %lf\n", sum/n, pow(pr,((dd)1)/n), n/isum);		
	}
}
