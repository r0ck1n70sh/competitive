#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	string A, B;
	scanf("%d", &T);
	while(T){
		cin>>A>>B;
		if(B.length()==1&&B[0]=='0') {
			printf("0\n");
			break;
		}
		
		reverse(A.begin(), A.end());
		reverse(B.begin(), B.end());
		
		if(A.length()<B.length())
			swap(A, B);
		
		A.push_back('0');
		while(B.length()!=A.length())
			B.push_back('0');
			
		int count=1;
		int carry=0;		
		for(int i=0; i<A.length(); i++){
			int sum= (A[i]-'0')+(B[i]-'0')+carry;			
			if(sum>1) {
				carry=1;
				count++;
			}
		}
		
		printf("%d\n", count);
		--T;
	}
	
	return 0;
}
