#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	
	while(t--){
		int n, d, cnt=0, days= 0;
		cin>>n>>d;
		
		for(int i=0,x; i<n; i++){
			cin>>x;
			if(x>= 80 || x<=9)
				cnt++;
		}
		
		days+= cnt/d;
		days+= (cnt%d > 0)?1:0;
		days+= (n-cnt)/d ;
		days+= ((n-cnt)%d > 0)?1:0;
		
		printf("%d\n", days);
	}

	return 0;
}
