#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	string A,B;
	scanf("%d", &t);
	while(t--){
		cin>>A>>B;
		if(B[0]=='0'){
			printf("%d\n", 0);
			continue;
		}		
		reverse(A.begin(), A.end());
		reverse(B.begin(), B.end());
		while(A.size()<B.size()) A+="0";
		while(B.size()<A.size()) B+="0";
		A+="0"; B+="0";
		
		int carry=0, ans=0, curr=0;
		for(size_t i=0; i<A.size(); i++) {
			carry= carry+(A[i]-'0')+(B[i]-'0');
			if(carry>1)
				curr++;
			else
				curr=0;
			carry/=2;
			ans= max(ans, curr);
		}
		printf("%d\n", ans+(B.find('1')!=string::npos));
	}
	return 0;
}
