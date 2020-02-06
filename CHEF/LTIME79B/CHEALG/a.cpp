#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		string s ,res; cin>>s;
		s.push_back('0');res.push_back(s[0]);
		for(int i=1,cnt=1;i<int(s.length());i++){
			if(s[i]!=s[i-1]) {
				while(cnt){
					res.push_back(cnt+'0'); cnt/=10;
				}	
				cnt=1; res.push_back(s[i]);
			}
			else cnt++; 
		}
		//cout<<res<<"\n";
		if(s.length()>res.length()) printf("YES\n");
		else printf("NO\n");
	}
}
