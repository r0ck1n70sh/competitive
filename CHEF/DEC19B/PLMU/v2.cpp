#include <bits/stdc++.h>
int arr[505];
int main(){
	int T, N;
	int t;
	scanf("%d", &T);
	while(T){
		t=0;
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", arr+i);
		for(int i=0; i<N; i++)
			for(int j=i+1; j<N; j++)
				if(arr[i]+arr[j]==arr[i]*arr[j])
					t++;
		printf("%d\n", t);
		T--;
	}
	return 0;
}
