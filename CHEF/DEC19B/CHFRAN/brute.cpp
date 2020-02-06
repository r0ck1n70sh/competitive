#include <bits/stdc++.h>
#define maxl 10
#define maxn 100
using namespace std;

int l[maxl], r[maxl], x[maxn];
int minidx(int arr[], int size) {
	int minE=INT_MAX, res=0;
	for(int i=0; i<size; i++)
		if(arr[i]<minE){
			minE= arr[i];
			res=i;
		}
	return res;
}
int maxidx(int arr[], int size) {
	int maxE=0, res=0;
	for(int i=0; i<size; i++)
		if(arr[i]>maxE){
			maxE= arr[i];
			res=i;
		}
	return res;
}
int main(){
	int t, n;
	scanf("%d", &t);
	while(t){
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d%d", l+i, r+i);
		
		memset(x, 0, sizeof(x));
		for(int i=0; i<n; i++) {
			for(int j=l[i]; j<=r[i]; j++)
				x[j]+=1;
		}
		
		int startidx= minidx(l,n);
		int endidx= maxidx(r,n);
		
		int minx= INT_MAX;
		for(int i=r[startidx]; i<=l[endidx]; i++){
			if(x[i]<minx)
				minx=x[i];
		}
		
		//if(minx>n-2)
			//printf("-1\n");
		//else
			printf("%d\n", minx);
					
		--t;
	}
	return 0;	
}
