#include <bits/stdc++.h>
#define max 1000

int main(){
    int n, m, q;
    int x, y;
    std::vector<std::vector<int>> graph(max);
    std::vector<int>::iterator it;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }	
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        scanf("%d%d", &x, &y);
        it=std::find(graph[x].begin(), graph[x].end(), y);
        if(it != graph[x].end())
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}
