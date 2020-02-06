#include <bits/stdc++.h>
using namespace std;
string solve(string &res, int n){
	if(n==1)
		return res;
	int f=-1;
	for(int i=2; i<=9; i++)
		if(n%i==0)
			f=i;
	if(f==-1){
		res.clear();
		res.push_back('-');
		res.push_back('1');
		return solve(res, 1);
	}
	res+=f+'0';
	return solve(res, n/f);		
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
	int n;
	scanf("%d", &n);
	if(n==0){
		printf("10\n");
		continue;
	}
	if(n==1){
		printf("1\n");
		continue;
	}
	string res="";
	res=solve(res, n);
	if(res!="-1")
		sort(res.begin(), res.end());
	cout<<res<<"\n";
	}
}
