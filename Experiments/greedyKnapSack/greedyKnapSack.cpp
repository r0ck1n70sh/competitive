#include <bits/stdc++.h>
int main() {
    int t, n, x, ans;
    int cap[10000];
    scanf("%d", &t);
    while(t) {
		ans=0;
        scanf("%d%d", &n, &x);
        for(int i=0; i<n; i++)
            scanf("%d", cap+i);
        
        std::sort(cap, cap+n);
        for(int i=0; i<n ; i++) {
            x-=cap[i];
            if(x<0)
                break;
            ans++;
        }
        printf("%d\n", ans);
        t--;
    }
}
