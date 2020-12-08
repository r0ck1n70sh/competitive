#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int arr[4][4];
vector<int> res;
void solve(int mov,int msk, int st[4]){
	if(mov>=4) {
		if(msk==15) {
			sort(st,st+4); int sum=0;
			for(int i=0;i<4;i++){
				if(st[i]==0) sum+=-100;
				else sum+=25*(i+1)*st[i];
			}
			res.push_back(sum);
		}
		else
			printf("sometime wrong!\n");
		return;
	}
	for(int tim=0;tim<4;tim++){
		if(msk&(1<<tim)) continue;
		int currst[4];
		for(int i=0;i<4;i++) currst[i]=st[i];
		currst[mov]=arr[mov][tim];
		solve(mov+1,msk+(1<<tim),currst);
	}
}
int main(){
	int t; cin>>t; long long sum=0;
	while(t--){
		int n; cin>>n; //cout<<n<<"\n";
		char mov; int tim; 
		for(int i=0;i<n;i++){
			scanf("\n%c%d",&mov,&tim);
			tim=(tim%12)/3;
			arr[mov-'A'][tim]+=1;
		}
		//cout<<"ok1\n";
		//for(int i=0;i<4;i++){
			//for(int j=0;j<4;j++) printf("%d ", arr[i][j]);
			//printf("\n");
		//}
		//cout<<"ok2\n";
		int st[]={0,0,0,0};
		solve(0,0,st);
		int max_prof=*max_element(res.begin(),res.end());
		//for(int i=0;i<int(res.size());i++) printf("%d ",res[i]);
		//printf(":%d\n", int(res.size()));
		sum+=max_prof;
		printf("%d\n", max_prof);
		memset(arr,0,sizeof(arr));
		res.clear();
	}
	printf("%lld\n", sum);
}
