#include <bits/stdc++.h>
using namespace std;
void subSeq(string&s, vector<string>&arr, string&ans, int idx){
	if((size_t)idx==s.length())
		return;	
	string t=ans+s[idx];
	arr.push_back(t);
	subSeq(s, arr, t, idx+1);
	subSeq(s, arr, ans, idx+1);	
}
int main(){
	int t, n;
	scanf("%d", &t);
	while(t--) {
		vector<string> arr;
		string s, empty="";
		scanf("%d", &n);
		cin>>s;
		subSeq(s, arr,empty, 0);
		sort(arr.begin(), arr.end());
		int k=0;
		for(size_t len=1; len<s.length(); len++) {
			int curr=0;
			set<string> q;
			for(size_t i=0; i<arr.size()-1; i++)
				if(arr[i].length()==len){
					if(q.count(arr[i])) {
						curr=len;
						//cout<<arr[i]<<"\n";
						break;
					}
					else
						q.insert(arr[i]);
				}
			k=max({k, curr});
			//arr.clear();
		}
		//for(auto it=arr.begin(); it!=arr.end(); it++)
			//cout<<*it<<" ";
		//printf("%lld\n", arr.size());
		printf("%d\n", k);
	}
	return 0;
}
