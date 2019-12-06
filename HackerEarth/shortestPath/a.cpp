#include <bits/stdc++.h>
#define max 1000000
int V[max][3];
int dist[10000+1];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);		
	for(int i=0; i<m; i++)
		scanf("%d%d%d", &V[i][0], &V[i][1], &V[i][2]);
	
	memset(dist, max, sizeof(dist));
	dist[1]=0;
	for(int i=1; i<n+1; i++)
		for(int j=0; j<m; j++)
			if(dist[V[j][0]]+V[j][2]<dist[V[j][1]])
				dist[V[j][1]]=dist[V[j][0]]+V[j][2];
	
	for(int i=2; i<n+1; i++)
		printf("%d ", dist[i]);
	printf("\n");
	return 0;
}
