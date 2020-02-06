#include <bits/stdc++.h>
#define maxl 31
using namespace std;
int countb(string &s){
	int count=0;
	for(int i=0; i<s.length(); i++)
		if(s[i]-'0')
			count++;
	return count;
}
void genb(int b, int n, vector<int>&arr, int i, int num){
	if(i==n) {
		if(b==0)
		arr.push_back(num);		
		return;
	}
	
	int t= num|(1<<i);
	
	genb(b-1, n, arr, i+1, t);
	
	genb(b, n, arr, i+1, num);
}
int countxor(int n1, int n2, int n){
	vector<int> arr1, arr2;
	genb(n1, n, arr1, 0, 0);
	//for(int i=0; i<arr1.size(); i++)
		//printf("%d ", arr1[i]);
	//printf("\n");
	genb(n2, n, arr2, 0, 0);
	//for(int i=0; i<arr2.size(); i++)
		//printf("%d ", arr2[i]);
	//printf("\n");
	set<int> s;
	if(arr1.size()<arr2.size())
		swap(arr1, arr2);
	for(int i=0; i<arr1.size(); i++)
		for(int j=0; j<arr2.size(); j++)
			s.insert(arr1[i]^arr2[j]);
	return s.size();
}
int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		string s1, s2;
		cin>>s1>>s2;
		int n1=countb(s1), n2=countb(s2);
		//printf("%d %d\n", n1, n2);
		printf("%d\n", countxor(n1,n2,n));
	}
	return 0;
}
