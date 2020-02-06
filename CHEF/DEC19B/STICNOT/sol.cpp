#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool comP(int a1, int a2){
	return(a1>a2);
}
void solve() {
	int n, x, y;
	scanf("%d", &n);
	ll *v= new ll[n];
	ll *e= new ll[n-1];
	for(int i=0; i<n-1; i++)
		scanf("%d%d%lld",&x,&y,e+i);
	sort(e, e+n-1, comP);
	for(int i=0; i<n; i++)
		scanf("%lld", v+i);
	sort(v, v+n, comP);
	int ans=0, i=0;
	if(v[i]>=e[0])
		++i;
	else
		++ans;
	for(int j=0; j<n-1; j++) {
		if(v[i]>=e[j])
			i++;
		else
			ans++;
	}
	printf("%d\n", ans);
	delete[] v;
	delete[] e;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}
