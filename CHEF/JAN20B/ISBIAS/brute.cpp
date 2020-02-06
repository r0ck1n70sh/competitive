#include <bits/stdc++.h>
#define maxl (int)(1e5+7)
using namespace std;
int arr[maxl];
int n;
int minseq(int l, int r){
	int res=0;
	for(int i=l; i<r; i++){
		int idx=i;
		bool flag=0;
		while(arr[idx]>arr[idx+1]){
			idx++;
			flag=1;
		}
		i=idx;
		if(flag)
			res++;
	}
	return res;	
}
int maxseq(int l, int r){
	int res=0;
	for(int i=l; i<r; i++){
		int idx=i;
		bool flag=0;
		while(arr[idx]<arr[idx+1]){
			idx++;
			flag=1;
		}
		i=idx;
		if(flag)
			res++;
	}
	return res;	
}
int main(){
	int q;
	scanf("%d%d", &n ,&q);
	for(int i=1; i<n+1; i++)
		scanf("%d", arr+i);
	int l, r;
	while(q--){
		scanf("%d%d", &l, &r);
		if(minseq(l,r)==maxseq(l,r))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
