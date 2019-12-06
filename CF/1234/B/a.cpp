#include <bits/stdc++.h>
#define maxl 1000000000
using namespace std;
bool vis[maxl];
int main() {
	int n, k;
	deque <int> Q;
	memset(vis, 0, sizeof vis);
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++) {
		int x;
		scanf("%d", &x);
		if(vis[x]==0) {
			Q.push_front(x);
			vis[x]=1;
		}
		if(Q.size()>k) {
			vis[Q.back()]=0;
			Q.pop_back();
		}
	}
	printf("%d\n", Q.size());
	while(!Q.empty()) {
		printf("%d ", Q.front());
		Q.pop_front();
	}
	return 0;
}
