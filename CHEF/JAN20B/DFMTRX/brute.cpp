#include <bits/stdc++.h>
#define maxl (int)(2e3+7)
#define F(i,a,b) for(int i=(int)(a); i<=(int)(b); i++)
int arr[maxl][maxl];
bool vis[2*maxl][maxl];
int n;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		bool flag=0;
		memset(vis, 0, sizeof(vis));
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		printf("%d: ", n);
		if(n==1){
			printf("Hooray\n1\n");
			continue;
		}
		//if(n&1){
			//printf("Boo\n");
			//continue;
		//}
		F(i,1,n)
			arr[i][i]=1;
		F(k,1,2*n-1){
			F(i,1,n){
				F(j,1,n){
					if(arr[i][j])
						continue;
					if(vis[k][i]||vis[k][j])
						continue;
					arr[i][j]=k;
					vis[k][i]=1; vis[k][j]=1;					
				}
			}
			F(i,1,n)
				if(!vis[k][i]){
					flag=1;
					break;
				}					
		}
		if(flag)
			printf("Boo\n");
		else {
			printf("Hurray\n");
			F(i,1,n){
				F(j,1,n)
					printf("%d ", arr[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}
