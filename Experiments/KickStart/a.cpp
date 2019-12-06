#include <bits/stdc++.h>
#define PII pair<int, int>
#define maxl 100001
using namespace std;
int main() {
    int t;
    int vis[maxl];
    vector<PII> s;
    int x, y;
    scanf("%d", &t);
    for(int k=1; k<=t; k++) {
		int n ,m;
        memset(vis,0,sizeof vis);
        scanf("%d%d", &n, &m);
        int sugar=0; int count=n-1;
        for(int i=0; i<m; i++) {
            scanf("%d%d", &x, &y);
            s.push_back({x,y});            
        }
		sort(s.begin(), s.end());
        for(int i=0; i<s.size(); i++) {
            int x1=s[i].first; int y1=s[i].second;
            if(vis[x1]<2&&vis[y1]<2) {
				vis[x1]++; vis[y1]++;
				sugar++; count--;	printf("+\n");
			}
			if(count==0) break;
        }
        for(int i=1; i<=n; i++) {
			if(count==0)	break;
			if(vis[i]<2) {
				for(int j=i+1; j<=n; j++) {
					if(vis[j]<2) {
						vis[j]++; vis[i]++;
						sugar+=2; count--;
					}
					if(vis[i]>1||count==0)	break;
				}
			}
		}
        printf("Case #%d: %d\n", k, sugar);
    }
    return 0;
}
