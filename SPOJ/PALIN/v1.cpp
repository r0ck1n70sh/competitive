#include <bits/stdc++.h>
#define ll long long unsigned int
using namespace std;

bool all9(string&s1, ll n){
	for(ll i=0; i<n; i++)
		if(s1[i]!='9')
			return false;
	return true;
}
int main(){
	int T;
	string str;
	scanf("%d", &T);
	
	while(T--){
		cin>>str;
		ll n= str.length();
		
		if(all9(str, n)){
			printf("1");
			for(ll i=0; i<n-1; i++)
				printf("0");
			printf("1\n");
			continue;
		}
		
		int i=n/2;
		int j=i;
		
		if((n&1)==0)
			i-=1;
			
		while(str[i]==str[j] && i>=0) {
			i--;
			j++;
		}
		
		if(str[i]<str[j] || i<0){
			i=n/2;
			j=i;
			if((n&1)==0)
				i--;
			int carry=1;
			while(i>=0){
				int num=((str[i]-'0')+carry);
				carry= num/10;
				str[i]= (num%10)+'0';
				str[j]=str[i];
				i--;
				j++;
			}
		}
		else{
			while(i>=0) {
				str[j]=str[i];
				i--;
				j++;
			}
		}
		cout<<str<<"\n";
	}
}
