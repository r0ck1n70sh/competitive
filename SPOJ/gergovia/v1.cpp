#include <bits/stdc++.h>
#define ll long long int
#define maxl (int)(1e5+5)
using namespace std;

ll arr[maxl];

int main(){
	int N;
	while(true){
		ll work=0;
		scanf("%d", &N);
		if(N==0)
			break;
			
		for(int i=0; i<N; i++)
			scanf("%lld", arr+i);
			
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				int y= arr[j];
				int x= arr[i];
				if(x==0)
					break;
				if(y==0)
					continue;
				if(x*y<0) {
					work+=min(abs(x), abs(y))*(j-i);
					if(abs(x)>abs(y)) {
						arr[i]= abs(x+y)*abs(x)/x;
						arr[j]= 0;
					}
					else {
						arr[i]= 0;
						arr[j]= abs(x+y)*abs(y)/y;
					}
				}
			}
		}
		printf("%lld\n", work);
	}
	return 0;
}
