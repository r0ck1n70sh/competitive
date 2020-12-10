#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<int> arr(n);
		
		for(int i=0; i<n; i++){
			if(i< k)
				arr[i]= (i+1);
			else
				arr[i]= -(i+1);
		}
		
		for(int i=0; i<n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	return 0;	
}
