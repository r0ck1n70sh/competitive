#include <bits/stdc++.h>
int maxs[8];
using namespace std;
int main(){
	int T, N;
	int p, s, sum;
	scanf("%d",&T);
	while(T){
		memset(maxs, 0, sizeof(maxs));
		scanf("%d", &N);
		while(N){
			scanf("%d%d", &p, &s);
			if(maxs[p-1]<s&&p<9)
				maxs[p-1]=s;
			N--;
		}
		sum=0;
		for(int i=0; i<8; i++)
			sum+=maxs[i];
		printf("%d\n", sum);
		T--;
	}
	return 0;
}
