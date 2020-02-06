#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, n;
	string s;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		cin>>s;
		map<char, int> last;
		int ans=0;
		for(int i=0; i<n; i++) {
			if(last.count(s[i]))
				ans= max({ans, n-(i-last[s[i]])});
			last[s[i]]=i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
