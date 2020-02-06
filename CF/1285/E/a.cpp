#include <bits/stdc++.h>
#define PII pair<int, int>
#define F first
#define S second
using namespace std;
bool comp(PII a, PII b){if(a.F!=b.F)return a.F<b.F; else return a.S<b.S;}
int main(){
	int t; scanf("%d", &t); while(t--){
		int n; scanf("%d", &n); vector<PII> arr;
		for(int i=0, l, r; i<n; i++) {scanf("%d%d",&l,&r);
			arr.push_back({l,r});}
		sort(arr.begin(), arr.end(), comp);
		int e=(arr.begin()->S)-1, res=0, flag=0;
		for(int i=0; i<n; i++){}
	}
}
