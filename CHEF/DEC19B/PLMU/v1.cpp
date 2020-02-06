#include <bits/stdc++.h>
int main(){
	int T, N;
	int x, t;
	scanf("%d", &T);
	while(T){
		t=0;
		scanf("%d", &N);
		while(N){
			scanf("%d", &x);
			if(x==2)
				t++;
			N--;
		}
		if(t>0)
			printf("%d\n", (t*(t-1))/2);
		else
			printf("0\n");
		T--;
	}
	return 0;
}

