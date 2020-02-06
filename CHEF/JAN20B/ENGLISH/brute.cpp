#include <bits/stdc++.h>
#define S second
#define F first 
using namespace std;
unordered_map<string, int> m;
int beauty(string &s1, string &s2){
	int pr=0, sf=0,n=min({s1.length(), s2.length()}), l1=s1.length(), l2=s2.length();
	for(int i=0; i<n; i++) {if(s1[i]!=s2[i])break; else pr++;}
	for(int i=1; i<n; i++) {if(s1[l1-i]!=s2[l2-i])break; else sf++;}
	return min({pr,sf})*min({pr,sf});
}
int main(){
	int t; scanf("%d",&t); while(t--){
		int n; string s;scanf("%d", &n);
		for(int i=0; i<n; i++) {cin>>s; if(m.count(s))m[s]++;
			else m.insert({s, 1});}
		int res=0; vector<string> v;
		for(auto it=m.begin(); it!=m.end(); it++){
			int val=it->S; string str=it->F; 
			res+=(val/2)*(str.length())*(str.length()); it->S=(val%2);
			if(it->S!=0) v.push_back(it->F);
		}
		sort(v.begin(), v.end()); int res1=res;
		for(int i=0; i<v.size(); i+=2) res+=beauty(v[i], v[i+1]);
		for(int i=v.size()-1; i>=0; i-=2) res1+=beauty(v[i], v[i-1]);
		printf("%d\n", max(res1, res)); m.clear();
	}
	return 0;
}
