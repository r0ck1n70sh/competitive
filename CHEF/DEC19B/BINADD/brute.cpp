#include <bits/stdc++.h>
using namespace std;
int b2d(string&s){
	int res=0;
	for(int i=0; i<s.length(); i++)
		if(s[i]-'0')
			res+=1<<(s.length()-i);
	//printf("%d\n", res);
	return res;
}
int main(){
	int t;
	scanf("%d", &t);
	string s1, s2;
	while(t--){
		int u, v;
		cin>>s1>>s2;
		int a= b2d(s1), b= b2d(s2);
		int count=0;
		while(b>0){
			++count;
			u=a^b;
			v=a&b;
			a=u;
			b=v<<1;
		}
		printf("%d\n",count);
	}
	return 0;
}
