#include <bits/stdc++.h>
int main(){
	int T, N;
	int x, t, z, res;
	scanf("%d", &T);
	while(T){
		t=0; z=0;
		scanf("%d", &N);
		while(N){
			scanf("%d", &x);
			if(x==2)
				t++;
			if(x==0)
				z++;
			N--;
		}
		res=0;
		if(t>0)
			res+=(t*(t-1))/2;
		if(z>0)
			res+=(z*(z-1))/2;
		printf("%d\n", res);
		T--;
	}
	return 0;
}

