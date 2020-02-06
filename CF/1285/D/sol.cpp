#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n; vector<int> a;
int solve(vector <int> &c, int bit){
	if(a.size()==0 || bit<0) return  0;
	vector <int> l, r;
	for(auto &i: c){
		if(((i>>bit)&1)) r.push_back(i);
		else l.push_back(i);
	}
	if(l.size()==0) return solve(r, bit-1);
	if(r.size()==0) return solve(l, bit-1);
	return min(solve(l, bit-1), solve(r, bit-1)) + (1<<bit);
}
int main(){
	cin>>n; a.resize(n);
	for(auto &i: a) cin>>i;
	cout << solve(a, 30) << "\n";
}
