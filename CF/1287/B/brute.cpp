#include <bits/stdc++.h>
#define maxl 1510
using namespace std;
int n, k;
vector<string> arr(maxl);
bool check(int i1, int i2, int i3){
	bool flag=1;
	for(int f=0; f<k; f++){
		bool c1= (arr[i1][f]==arr[i2][f]);
		bool c2= (arr[i2][f]==arr[i3][f]);
		bool c3= (arr[i3][f]==arr[i1][f]);

		if(c1+c2+c3<3&&c1+c2+c3>0){
			flag=0;
			break;
		}			
	}
	//if(flag)
		//printf("%d %d %d\n", i1, i2, i3);
	return flag;
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	int res=0;
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			for(int t=j+1; t<n; t++){
				if(check(i,j,t))
					res++;
			}
	printf("%d\n", res);			
}
