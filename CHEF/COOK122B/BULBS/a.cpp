#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n,k;
	string s;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d\n",&n, &k);
		cin>>s;
		vector<pair<int, int>> arr;
		
		int sum_cut=0, cnt=0, cut=0, sum_z=0;
		for(int i=0; i<n; i++){
			if(i==n-1 || s[i]!=s[i+1]){
				if(s[i]=='0'){
					if(i==n-1) --cut;
					
					arr.push_back({cnt+1, cut+1});
					sum_cut+= cut+1;
					cnt=0;
					cut=0;
					sum_z++;
				}
				else
					cut++;
			}
			else{
				if(s[i]=='0') {
					cnt++;
					sum_z++;
				}
			}
			
			//printf("%d:{%d,%d}\n", i, cnt, cut);
		}
		
		//cout<<s<<endl;
		//for(int i=0; i<arr.size(); i++)
			//printf("%d:%d ", arr[i].first, arr[i].second);
		//printf("\n");
		
		if(k==0){
			printf("%d\n", sum_z);
			continue;
		}
				
		if(k==n-1 || sum_cut<=k){
			printf("0\n");
			continue;
		}
		
		sort(arr.begin(), arr.end());
		
		int res=0, i=0, sum_cut1= sum_cut;
		while(sum_cut1>k){
			res+=arr[i].first;
			sum_cut1-=arr[i].second;
			i++;
		}
		
		if(sum_cut-sum_cut1<=k)
			printf("%d\n", min(res, sum_z-res));
			
		else printf("%d\n", res);
	}
}
