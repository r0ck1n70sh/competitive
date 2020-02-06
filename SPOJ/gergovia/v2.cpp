#include <bits/stdc++.h>
#define ll long long int
#define maxl (int)(1e5+5)
using namespace std;

ll arr[maxl];

int main(){
	int N;
	while(true){
		scanf("%d", &N);
		if(N==0)
			break;
			
		for(int i=0; i<N; i++)
			scanf("%lld", arr+i);
			
		ll work= 0;
		ll acc= arr[0];
		for(int i=1; i<N; i++){
			work+=abs(acc);
			acc+= arr[i];
		}	
		printf("%lld\n", work);
	}
	return 0;
}
