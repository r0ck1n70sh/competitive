#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll a,b,c,d,e,s,p;
		int n;
		scanf("%d", &n);
		p=(ll)pow(10,n);
		scanf("%lld", &a);
		s=a+2*p;
		//printf("%lld\n",s);
		cout<<s<<endl;
		scanf("%lld", &b);
		c=p-b;
		//printf("%lld\n",c);
		cout<<c<<endl;
		scanf("%lld", &d);
		e=p-d;
		//printf("%lld\n", e);
		cout<<e<<endl;		
		//if(a+b+c+d+e==s)
			//printf("Correct\n");
		scanf("%d", &n);
		if(n==-1)
			break;		
	}
	return 0;
}
