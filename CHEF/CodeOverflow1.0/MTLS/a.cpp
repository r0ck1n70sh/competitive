#include <bits/stdc++.h>
using namespace std;
int freq(string &s, string &pat){
	int m= pat.length();
	int n= s.length();
	int res=0;	
	for(int i=0; i<=n-m; i++){
		int j;
		for(j=0; j<m; j++)
			if(s[i+j]!=pat[j])
				break;
		if(j==m){
			res+=1;
			j=0;
		}
	}
	return res;
}
int main(){
	string s, pat;
	cin>>s>>pat;
	printf("%d\n", freq(s, pat));
}
