#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
	string s1, s2="";
	cin>>s1;
	for(size_t i=0; i<s1.length(); i++){
		if(s1[i]=='#'){
			s2.pop_back(); s2.pop_back();
			int k=0, idx=i;
			k=10*(s1[idx-2]-'0')+(s1[idx-1]-'0');
			s2.push_back('a'+k-1);
		}
		else{
			s2.push_back('a'+(s1[i]-'0')-1);
		}
	}
	cout<<s2<<"\n";	
	}
}
