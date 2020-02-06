#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,a,b,c,k,f=0; scanf("%d",&n);
		for(int i=2;i*i<n;i++){
			if(n%i==0){
				a=i; k=n/i;
				for(int j=2;j*j<k;j++){
					if(k%j==0&&j!=a&&k/j!=a){
						b=j; c=k/j; f=1; break;
					}
				}
			}
			if(f) break;		
		}
		if(f) printf("YES\n%d %d %d\n",a,b,c);
		else printf("NO\n");
	}
	return 0;
}
