#include <bits/stdc++.h>
#define maxl 8
#define maxl1 (1<<8)
using namespace std;
int main() {
	int maxi=0;
	vector <pair<int, int>> q;
	int x, y;
	int p;
	int val[maxl];	
	for(int i=0; i<maxl; i++)
		scanf("%d", val+i);
	scanf("%d", &p);
	for(int i=0; i<p; i++) {
		scanf("%d%d", &x, &y);
		q.push_back({x-1, y-1});
	}
	for(int bit=0; bit<(1<<8); ++bit) {
		bool f=1;
		for(int i=0; i<p; i++) {
			int a=q[i].first, b=q[i].second;
			if(bit&(1<<a)&&bit&(1<<b)) {
				f=0;
				break;
			}
		}
		if(!f) continue;
		int sum=0;
		for(int i=0; i<maxl; i++) {
			if(bit&(1<<i))
				sum+=val[i];
		}
		if(sum>maxi)
			maxi=sum;
	}
	printf("%d\n", maxi);
	return 0;
}
