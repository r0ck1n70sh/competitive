#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n, k; cin>>n>>k;
		string s; cin>>s;
		
		int start=0;
		while(s[start]=='0')
			start++;
			
		int end= n-1;
		while(s[end]=='0')
			end--;
		
		vector<int> offs;	
		int notAdded=1, stoff=start, endoff= n-1-end;
		if(k%2==0 && stoff!=0 && endoff!=0){
			notAdded=0;
			offs.push_back(stoff+endoff);
		}
		
		int cnt=0, sumz=stoff+endoff;
		
		for(int i=start; i<=end; i++){
			if(s[i]=='0'){
				cnt++;
				sumz++;
			}
			else{
				if(cnt>0)
					offs.push_back(cnt);
				cnt=0;
			}
		}
		
		if(k==0){
			printf("%d\n", sumz);
			continue;
		}
		
		if(k==1){
			printf("%d\n", sumz - max(stoff, endoff));
			continue;
		}
		
		sort(offs.begin(), offs.end(), greater<int>());
		
		int sumct= 0;
		if(k%2)
			sumct+= max(stoff, endoff);
		
		if(k%2 ==0 && notAdded)
			offs[k/2-1] = max({offs[k/2-1], stoff, endoff});
			
		for(int i=0; i<k/2; i++)
			sumct += offs[i];
			
		printf("%d\n", sumz-sumct);
	}
}
