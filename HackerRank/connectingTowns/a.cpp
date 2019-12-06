#include <stdio.h>
#include <stdlib.h>
#define ll long long unsigned int
const ll M=1234567;
int main() {
    int t, n, n1;
    ll ans;
    scanf("%d", &t);
    while(t) {
        ans=1;
        scanf("%d", &n);
        while(--n) {
            scanf("%d", &n1);
            ans=(ans*n1)%M;
        }
        printf("%llu\n", ans);
        --t;
    }
    return 0;
}
