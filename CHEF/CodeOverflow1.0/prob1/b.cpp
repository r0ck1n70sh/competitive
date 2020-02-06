#include <bits/stdc++.h>
#define maxl 10000
using namespace std;
vector<int> arr(maxl);
using namespace std;
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.begin()+n, greater<int>());
	int key=arr[k-1], curr=k;
	//while(k){
		//if(key>arr[curr]){
			//key=arr[curr]
		//}
		//curr++;
		//k--;
	//}
	int extra=0;
	while(key==arr[curr]){
		extra++;
		curr++;
	}
	printf("%d\n",extra+k);
}


