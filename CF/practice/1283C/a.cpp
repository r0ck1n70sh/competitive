#include <bits/stdc++.h>
using namespace std;
const int maxl=2e5+1;
int g[maxl], r[maxl];
int main(){
	int n; cin>>n;
	memset(g,0,sizeof(g));
	memset(r,0,sizeof(r));
	for(int i=1,x;i<=n;i++){
		cin>>x; g[i]=x; if(x>0) r[x]=i;
	}
	for(int i=1;i<=n;i++) cout<<r[i]<<" ";
	cout<<"\n";
	int i=1,j=1;
	while(i<=n){
		while(g[i]!=0&&i<n) i++;
		while(r[j]!=0&&j<n) j++;
		g[i]=j; r[j]=i;
		i++;j++;
	}
	for(int i=1;i<=n;i++) cout<<g[i]<<" ";
	cout<<"\n";
}
