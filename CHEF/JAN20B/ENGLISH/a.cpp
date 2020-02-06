#include <bits/stdc++.h>
#define maxl (int)(1e5+7)
#define sqr(a) (int)(a)*(int)(a)
using namespace std;
int n;
array<string, maxl> arr;
//bool vis[maxl];
int prlen(string s1, string s2){
	if(s1.length()<s2.length())
		swap(s1, s2);
	int i=0, j=0;
	while(s1[i]==s2[j]&&j<s2.length()) {
		i++; j++;
	}
	return i;
}
int sflen(string s1, string s2){
	if(s1.length()<s2.length())
		swap(s1, s2);
	int i=s1.length()-1, j=s2.length()-1;
	while(s1[i]==s2[j]&&j>=0) {
		i--; j--;
	}
	return s1.length()-i-1;
}
int minsq(string &s1, string &s2){
	return sqr(min(prlen(s1,s2), sflen(s1,s2))); 
}
int solve(int idx) {
	if(idx>=n)
		return 0;
	return max({minsq(arr[idx], arr[idx+1])+solve(idx+2), solve(idx+1)});
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		//memset(vis, 0, sizeof(vis));
		scanf("%d", &n);./
		for(int i=0; i<n; i++)
			cin>>arr[i];
		sort(arr.begin(), arr.begin()+n);
		//for(int i=0; i<n; i++)
			//cout<<arr[i]<<" ";
		//printf("\n");
		printf("%d\n", solve(0));
		//for(int i=0; i<n-1; i++)
			//printf("{pr:%d sf:%d}\n", prlen(arr[i], arr[i+1]), sflen(arr[i], arr[i+1]));			
	}
	return 0;
}
