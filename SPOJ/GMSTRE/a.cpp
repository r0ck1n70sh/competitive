#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
class level{
	public:
		int h,e,a,l;
	//level(int h, int e, int a){
		//this.h=h;
		//this.e=e;
		//this.a=a;
	//}
};
bool comp(level a, level b){
	if(a.h!=b.h) return a.h>b.h;
	if(a.e!=b.e) return a.e<b.e;
	return a.a>b.a;
}
int main(){
	int n; cin>>n;
	vector<level> arr(n);
	for(int i=0;i<n;i++) {
		cin>>arr[i].h>>arr[i].e>>arr[i].a;
		arr[i].l=i;
	}
	if(n==1) {printf("Easiest and Hardest is level 1\n"); exit(0);}
 	sort(arr.begin(),arr.end(), comp);
	//for(int i=0;i<n;i++) printf("%d ",arr[i].l+1); printf("\n");
	printf("Easiest is level %d\n", arr[0].l+1);
	printf("Hardest is level %d\n", arr[n-1].l+1);
	return 0;
}
