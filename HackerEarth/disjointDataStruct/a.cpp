#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define maxl 1001
using namespace std;
int arr[maxl], size[maxl];
int root(int);
void weighUnion(int, int);
void printSizeArr();
void initialize();
int n, m;
int main() {
	int x, y;
	scanf("%d%d",&n,&m);
	initialize();
	while(m) {
		scanf("%d%d",&x,&y);
		weighUnion(x,y);
		printSizeArr();
		--m;
	}
	return 0;
}
int root(int x) {
	while(x!=arr[x]) {
		arr[x]=arr[arr[x]];
		x=arr[x];
	}
	return x;	
}
void weighUnion(int x, int y) {
	int rootx=root(x);
	int rooty=root(y);
	
	if(size[rootx]>size[rooty]) {
		arr[rooty]=rootx;
		size[rootx]+=size[rooty];
	}
	else {
		arr[rootx]=rooty;
		size[rooty]+=size[rootx];
	}
}
void initialize() {
	F(i,0,n) {
		arr[i]=i;
		size[i]=1;
	}
}
void printSizeArr() {
	vector<int> out;
	F(i,0,n)
		if(arr[i]==i)
			out.push_back(size[i]);
	sort(out.begin(), out.end());
	for(auto it=out.begin(); it!=out.end(); it++)
		printf("%d ", *it);
	printf("\n");
}
