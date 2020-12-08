#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("out", "w", stdout);
	int t; scanf("%d\n", &t);
	while(t--){
		vector<bool> R(8,0), C(8,0); char arr[8][8]; int f=1, r=0;
		for(int i=0;i<8;i++)
			scanf("%s", arr[i]);
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++) {				
				if(arr[i][j]=='R'){
					if(R[i]==1) f=0;
					if(C[j]==1) f=0;
					R[i]=1; C[j]=1; r++;
				}
			}
		//for(int i=0;i<8;i++) {
			//printf("%s", arr[i]);
			//printf("\n");
		//}
		if(f&&r==8) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
